#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n, v;
int weights[10001];
int values[10001];
int main() {
  cin >> n >> v;
  for (int i = 0; i < n; i++) {
    cin >> weights[i] >> values[i];
  }
  vector<vector<int>> dp(n+1,vector<int>(v+1,0));
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= v; j++) {
      if (j < weights[i - 1]) {
        dp[i][j] = dp[i - 1][j];
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - weights[i - 1]] + values[i - 1]);
      }
    }
  }
  cout << dp[n][v] << endl;
  return 0;
}