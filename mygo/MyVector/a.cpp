#include <cstddef>
#include <cstring>
#include <iostream>
#include <memory>
using namespace std;
template <class T> class MyVector {
public:
  MyVector(const T *src) {
    if (src != nullptr) {
      int size = strlen(src);
      data = new T[size + 1];
      length = size;
      memcpy(data, src, (size + 1) * sizeof(T));
    } else {
      data = nullptr;
      length = 0;
    }
  };

  MyVector(const MyVector &src) {
    if (src.data != nullptr) {
      length = src.length;
      data = new T[length + 1];
      memcpy(data, src.data, (length + 1) * sizeof(T));
    }
  }

  MyVector &operator=(const MyVector &src) {
    if (this != &src) {
      drop();
      length = src.length;
      data = new T[length + 1];
      memcpy(data, src.data, (length + 1) * sizeof(T));
    }
    return *this;
  }

  MyVector(MyVector &&src) {
    data = src.data;
    length = src.length;
    src.data = nullptr;
    src.length = 0;
  }
  MyVector &operator=(MyVector &&src) {
    if (this != &src) {
      drop();
      data = src.data;
      length = src.length;
      src.data = nullptr;
      src.length = 0;
    }
    return *this;
  }

  void drop() {
    delete[] data;
    data = nullptr;
    length = 0;
  }

  ~MyVector() { drop(); }

  T &operator[](size_t index) { return data[index]; }

  const T &operator[](size_t index) const { return data[index]; }
  void print() const {
    if (data != nullptr) {
      std::cout << data << std::endl;
    }
  }

private:
  T *data = nullptr;
  int length = 0;
};

int main() {
  MyVector<char> str1("Hello, world!"); // 使用构造函数初始化
  str1.print();                         // 打印

  MyVector<char> str2 = str1; // 使用拷贝构造
  str2.print();

  MyVector<char> str3("Temporary");
  str3 = str1; // 使用拷贝赋值
  str3.print();

  MyVector<char> str4 = std::move(str1); // 使用移动构造
  str4.print();
  str1.print(); // str1 已经被移动，数据应该为空

  MyVector<char> str5("Move Assignment");
  str5 = std::move(str4); // 使用移动赋值
  str5.print();
  str4.print(); // str4 已经被移动，数据应该为空

  cout << "Character at index 1 of str5: " << str5[1]
       << std::endl; // 使用下标操作符

  return 0;
}