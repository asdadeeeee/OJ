#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <memory>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;
int n, m, T;
int R[10001];
int C[10001];
vector<vector<int>> memo;
int nextx(int curx) {}
int func(int beginx, int beginy, int endx, int endy) {}
int main() {
  cin >> n >> m >> T;
  memo.resize(n, vector<int>(m, -1));
  for (int i = 0; i < n; i++) {
    cin >> R[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> C[i];
  }
  while (T--) {
    int ans = 0;
    ans = func();
    cout << ans << endl;
  }
  // 请在此输入您的代码
  return 0;
}