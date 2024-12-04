#include <iostream>
using namespace std;

class B {
public:
  int x;
  int y;
};

class A {
public:
  static B b;
  void test() {
    b.x = 1;
    cout << b.x << "print";
  }
};

int main() {
  A a;
  a.test();
}