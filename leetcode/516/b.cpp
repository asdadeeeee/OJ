#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
  int longestPalindromeSubseq(string s) {
    int n = s.length();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
      dp[i][i] = 1;
    }
    for (int i = n - 1; i >= 0; i--) {
      for (int j = i + 1; j < n; j++) {
        if (s[i] == s[j]) {
          dp[i][j] = dp[i + 1][j - 1] + 2;
        } else {
          dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
        }
      }
    }
    return dp[0][n - 1];
  }
};