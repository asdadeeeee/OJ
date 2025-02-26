#include <cstddef>
#include <future>
#include <iostream>
#include <map>
#include <queue>
#include <thread>
#include <utility>
#include <vector>
using namespace std;

void func(int **a) {
  cout << *a << endl;
  *a = nullptr;
  return;
}
int main() {
  int b = 10;
  int *ptr = &b;
  func(&ptr);
  if (ptr == nullptr) {
    cout << "null" << endl;
  } else {
    cout << "not null" << endl;
  }
  return 0;
}