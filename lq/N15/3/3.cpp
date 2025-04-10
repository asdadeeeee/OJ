#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;
int c[10] = {1, 0, 0, 0, 1, 0, 1, 0, 2, 1};
int getcir(int num) {
  if (num == 0) {
    return 1;
  }
  int res = 0;
  int tail = 0;
  while (num > 0) {
    tail = num % 10;
    res += c[tail];
    num = num / 10;
  }
  return res;
}
struct cmp {
  bool operator()(const int &a, const int &b) {
    int ca = getcir(a);
    int cb = getcir(b);
    if (ca != cb) {
      return ca < cb;
    }
    return a < b;
  }
};
void print(vector<int> &a) {
  for (auto n : a) {
    cout << n << " ";
  }
}
int main() {
  int n;
  cin >> n;
  vector<int> A(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  sort(A.begin(), A.end(), cmp());
  print(A);
  return 0;
}