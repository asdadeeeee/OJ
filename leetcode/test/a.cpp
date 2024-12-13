#include <iostream>
#include <vector>
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
  int a = 0;
  while (a < 10) {
    a = 10;
    cout << a;
    continue;
  }
}