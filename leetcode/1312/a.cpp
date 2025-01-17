#include <cstring>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  int minInsertions(string s) {
    int n = s.size();
    int dp[n][n];
    memset(dp, 0, sizeof(dp));
    for (int i = n - 1; i >= 0; i--) {
      dp[i][i] = 0;
      for (int j = i + 1; j < n; j++) {
        if (s[i] == s[j]) {
          dp[i][j] = dp[i + 1][j - 1];
        } else {
          dp[i][j] = min(dp[i + 1][j] + 1, dp[i][j - 1] + 1);
        }
      }
    }
    return dp[0][n - 1];
  }
};