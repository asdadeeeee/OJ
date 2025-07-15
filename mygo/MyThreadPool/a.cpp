#include <condition_variable>
#include <functional>
#include <future>
#include <iostream>
#include <memory>
#include <mutex>
#include <queue>
#include <stdexcept>
#include <thread>
#include <type_traits>
#include <utility>
#include <vector>
using namespace std;

class MyThreadPool {
public:
  MyThreadPool(int size) {
    running = true;
    for (int i = 0; i < size; i++) {
      workers.emplace_back(([this] {
        while (true) {
          function<void()> task;
          {
            unique_lock<mutex> lock(queue_mutex);
            condition.wait(lock,
                           ([this] { return !running || !tasks.empty(); }));
            if (!running && tasks.empty()) {
              return;
            }
            task = std::move(tasks.front());
            tasks.pop();
          }
          task();
        }
      }));
    };
  }

  ~MyThreadPool() {
    {
      unique_lock<mutex> lock(queue_mutex);
      running = false;
    }
    condition.notify_all();
    for (auto &thread : workers) {
      thread.join();
    }
  }

  template <typename F, typename... Args>
  auto push_task(F &&f, Args &&...args)
      -> future<typename result_of<F(Args...)>::type> {

    using return_type = typename result_of<F(Args...)>::type;
    auto task = make_shared<packaged_task<return_type()>>(
        bind(forward<F>(f), forward<Args>(args)...));
    auto res = task->get_future();
    {
      unique_lock<mutex> lock(queue_mutex);
      if (!running) {
        throw runtime_error("error");
      }
      tasks.push([task] { (*task)(); });
    }
    condition.notify_one();
    return res;
  }

private:
  vector<thread> workers;
  bool running;

  queue<std::function<void()>> tasks;
  condition_variable condition;
  mutex queue_mutex;
};
// 示例函数：用于测试
int add(int a, int b) { return a + b; }

std::string concat(const std::string &s1, const std::string &s2) {
  return s1 + s2;
}
int main() {
  try {
    // 创建一个包含4个工作线程的线程池
    MyThreadPool pool(4);

    // 示例 1：提交普通函数任务
    auto future1 = pool.push_task(add, 5, 3);
    std::cout << "Task 1 result: " << future1.get() << std::endl; // 预期输出: 8

    // 示例 2：提交 lambda 表达式任务
    auto future2 = pool.push_task([](int x, int y) { return x * y; }, 4, 5);
    std::cout << "Task 2 result: " << future2.get()
              << std::endl; // 预期输出: 20

    // 示例 3：提交字符串操作任务
    auto future3 = pool.push_task(concat, "Hello, ", "World!");
    std::cout << "Task 3 result: " << future3.get()
              << std::endl; // 预期输出: Hello, World!

    // 示例 4：提交延迟任务并异步等待
    std::vector<std::future<int>> futures;
    for (int i = 1; i <= 5; ++i) {
      futures.push_back(pool.push_task(
          [](int n) {
            std::this_thread::sleep_for(
                std::chrono::milliseconds(100)); // 模拟耗时任务
            return n * n;
          },
          i));
    }
    for (auto &fut : futures) {
      std::cout << "Task 4 result: " << fut.get()
                << std::endl; // 预期输出: 1, 4, 9, 16, 25
    }

    // 示例 5：测试异常情况（向已停止的线程池提交任务）
    {
      MyThreadPool temp_pool(1);
      // temp_pool 超出作用域后销毁，running 置为 false
    }
    // 以下代码会抛出异常，因为线程池已停止
    // MyThreadPool temp_pool(1);
    // auto future_error = temp_pool.push_task(add, 1, 2); // 会抛出
    // std::runtime_error
  } catch (const std::exception &e) {
    std::cerr << "Exception caught: " << e.what() << std::endl;
  }

  return 0;
}