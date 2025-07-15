#include <cstddef>
#include <cstring>
#include <iostream>
#include <memory>
using namespace std;
class MyString {
public:
  MyString(const char *src) {
    if (src != nullptr) {
      int size = strlen(src);
      data = new char[size + 1];
      length = size;
      memcpy(data, src, size + 1);
    } else {
      data = nullptr;
      length = 0;
    }
  };

  MyString(const MyString &src) {
    if (src.data != nullptr) {
      length = src.length;
      data = new char[length + 1];
      memcpy(data, src.data, length + 1);
    }
  }

  MyString &operator=(const MyString &src) {
    if (this != &src) {
      drop();
      length = src.length;
      data = new char[length + 1];
      memcpy(data, src.data, length + 1);
    }
    return *this;
  }

  MyString(MyString &&src) {
    data = src.data;
    length = src.length;
    src.data = nullptr;
    src.length = 0;
  }
  MyString &operator=(MyString &&src) {
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

  ~MyString() { drop(); }

  char &operator[](size_t index) { return data[index]; }

  const char &operator[](size_t index) const { return data[index]; }
  void print() const {
    if (data != nullptr) {
      std::cout << data << std::endl;
    }
  }

private:
  char *data = nullptr;
  int length = 0;
};

int main() {
  MyString str1("Hello, world!"); // 使用构造函数初始化
  str1.print();                   // 打印

  MyString str2 = str1; // 使用拷贝构造
  str2.print();

  MyString str3("Temporary");
  str3 = str1; // 使用拷贝赋值
  str3.print();

  MyString str4 = std::move(str1); // 使用移动构造
  str4.print();
  str1.print(); // str1 已经被移动，数据应该为空

  MyString str5("Move Assignment");
  str5 = std::move(str4); // 使用移动赋值
  str5.print();
  str4.print(); // str4 已经被移动，数据应该为空

  cout << "Character at index 1 of str5: " << str5[1]
       << std::endl; // 使用下标操作符

  return 0;
}