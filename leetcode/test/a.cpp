#include <iostream>
#include <string.h>
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
  vector<int> nums{0, 1, 2, 3, 4};
  int begin = 1;
  int end = 3;
  vector<int> temp;
  temp.resize(end - begin + 1);
  memcpy(temp.data(), nums.data() + begin, temp.size() * sizeof(int));
  for (auto n : temp) {
    cout << n;
  }
}