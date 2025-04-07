#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <vector>

#include <cmath>
#include <cstring>
#include <numeric>
#include <string>
using namespace std;
int n, m;
int main() {
  cin >> n >> m;
  vector<int> dp(n + 1, 0);
  dp[0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (i >= j) {
        dp[i] += dp[i - j];
      }
    }
  }
  cout << dp[n] << endl;
  return 0;
}