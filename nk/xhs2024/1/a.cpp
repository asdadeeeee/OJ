#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int main() {
  double ans;
  double n;
  cin >> n;
  ans = n * (n - 1) / 2;
  ans = 1 / ans;
  printf("%.10lf", ans);
  return 0;
}