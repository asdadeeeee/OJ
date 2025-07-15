#include <iostream>
using namespace std;
template <typename T> class MyUniquePtr {
public:
  MyUniquePtr() { ptr = nullptr; }
  MyUniquePtr(T *p) { ptr = p; }

  T &operator*() { return *ptr; }
  T *operator->() { return ptr; }
  MyUniquePtr(MyUniquePtr &&other) {
    ptr = other.ptr;
    other.ptr = nullptr;
  }
  MyUniquePtr &operator=(MyUniquePtr &&other) {
    if (this != &other) {
      release();
      ptr = other.ptr;
      other.ptr = nullptr;
    }
    return *this;
  }

  ~MyUniquePtr() { release(); }
  // 重置指针
  void reset(T *p = nullptr) noexcept {
    delete ptr;
    ptr = p;
  }

  // 检查是否为空
  bool is_null() const noexcept { return ptr == nullptr; }

private:
  MyUniquePtr(const MyUniquePtr &other) = delete;
  MyUniquePtr &operator=(const MyUniquePtr &other) = delete;
  void release() {
    delete ptr;
    ptr = nullptr;
  }
  T *ptr;
};

int main() {
  // 创建唯一指针
  MyUniquePtr<int> up1(new int(42));
  std::cout << "up1 value: " << *up1 << ", is null: " << up1.is_null()
            << std::endl;

  // 移动构造
  MyUniquePtr<int> up2 = std::move(up1);
  std::cout << "up2 value: " << *up2 << ", is null: " << up2.is_null()
            << std::endl;
  std::cout << "up1 is null: " << up1.is_null() << std::endl;

  // 移动赋值
  MyUniquePtr<int> up3;
  up3 = std::move(up2);
  std::cout << "up3 value: " << *up3 << ", is null: " << up3.is_null()
            << std::endl;
  std::cout << "up2 is null: " << up2.is_null() << std::endl;

  // 重置
  up3.reset(new int(100));
  std::cout << "up3 after reset: " << *up3 << std::endl;

  // 释放
  up3.reset();
  std::cout << "up3 is null after release: " << up3.is_null() << std::endl;

  return 0;
}