#include <iostream>
using namespace std;
template <typename T> class MySharedPtr {
public:
  MySharedPtr() {
    count = nullptr;
    data = nullptr;
  }
  MySharedPtr(T *ptr) {
    data = ptr;
    count = new int(1);
  }
  MySharedPtr(const MySharedPtr &other) {
    count = other.count;
    data = other.data;
    if (count) {
      (*count)++;
    }
  }
  MySharedPtr(MySharedPtr &&other) {
    count = other.count;
    data = other.data;
    other.count = nullptr;
    other.data = nullptr;
  }
  MySharedPtr &operator=(const MySharedPtr &other) {
    if (this != &other) {
      release();
      count = other.count;
      data = other.data;
      if (count) {
        (*count)++;
      }
    }
    return *this;
  }
  MySharedPtr &operator=(MySharedPtr &&other) {
    if (this != &other) {
      release();
      count = other.count;
      data = other.data;
      other.count = nullptr;
      other.data = nullptr;
    }
    return *this;
  }

  ~MySharedPtr() { release(); }

  T &operator*() { return *data; }
  T *operator->() { return data; }
  // 获取引用计数
  size_t use_count() const { return count ? *count : 0; }

  // 检查是否为空
  bool is_null() const { return data == nullptr; }

private:
  void release() {
    if (count) {
      (*count)--;
      if ((*count) == 0) {
        Drop();
      }
    }
  }
  void Drop() {
    delete count;
    count = nullptr;
    delete data;
    data = nullptr;
  }

  int *count;
  T *data;
};

int main() {
  // 创建共享指针
  MySharedPtr<int> sp1(new int(42));
  std::cout << "sp1 value: " << *sp1 << ", count: " << sp1.use_count()
            << std::endl;

  // 拷贝构造
  MySharedPtr<int> sp2 = sp1;
  std::cout << "sp2 value: " << *sp2 << ", count: " << sp1.use_count()
            << std::endl;

  // 移动构造
  MySharedPtr<int> sp3 = std::move(sp1);
  std::cout << "sp3 value: " << *sp3 << ", count: " << sp3.use_count()
            << std::endl;
  std::cout << "sp1 is null: " << sp1.is_null() << std::endl;

  // 移动赋值
  MySharedPtr<int> sp4;
  sp4 = std::move(sp3);
  std::cout << "sp4 value: " << *sp4 << ", count: " << sp4.use_count()
            << std::endl;
  std::cout << "sp3 is null: " << sp3.is_null() << std::endl;

  return 0;
}