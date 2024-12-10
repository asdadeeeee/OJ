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
  std::vector<int> nums = {1, 2, 3};
  auto iter = nums.begin();
  nums.erase(iter);
  cout << *iter;
}