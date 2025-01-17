#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int n;
int m;
int price[1001];
int dp[1001][1001];

int solve() {
  if (m < 5) {
    return m;
  }
  for (int i = 1; i <= n - 1; i++) {
    for (int j = 1; j <= m - 5; j++) {
      dp[i][j] = dp[i - 1][j];
      if (j >= price[i - 1]) {
        dp[i][j] = max(dp[i][j], dp[i - 1][j - price[i - 1]] + price[i - 1]);
      }
    }
  }
  return m - dp[n - 1][m - 5] - price[n - 1];
}
int main() {
  while (cin >> n && n) {
    memset(price, -1, sizeof(price));
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++) {
      cin >> price[i];
    }
    cin >> m;

    sort(price, price + n);
    int res = solve();
    cout << res << endl;
  }
  return 0;
}