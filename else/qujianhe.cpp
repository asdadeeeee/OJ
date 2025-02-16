#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int> A;
vector<int> s;
int a, b;
int sum() {
  int right = b >= 0 ? s[b] : 0;
  int left = a > 0 ? s[a - 1] : 0;
  return right - left;
}
int main() {
  cin >> n;
  A.resize(n);
  s.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
    if (i > 0) {
      s[i] = s[i - 1] + A[i];
    } else {
      s[i] = A[i];
    }
  }
  while (scanf("%d %d", &a, &b) != EOF) {
    cout << sum() << endl;
  }
  return 0;
}