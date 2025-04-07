#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
  inline bool rev(const string &s, int begin, int end,
                  vector<vector<int>> &memo) {
    if (begin > end) {
      return true;
    }
    if (memo[begin][end] != 0) {
      return memo[begin][end] == 1 ? true : false;
    }
    if (s[begin] != s[end]) {
      memo[begin][end] = -1;
      return false;
    } else {
      if (rev(s, begin + 1, end - 1, memo)) {
        memo[begin][end] = 1;
        return true;
      } else {
        memo[begin][end] = -1;
        return false;
      }
    }
  }
  int countSubstrings(string s) {
    int n = s.length();
    vector<int> dp(n + 1, 0);
    vector<vector<int>> memo(n, vector<int>(n, 0));
    for (int i = 1; i <= n; i++) {
      dp[i] = dp[i - 1] + 1;
      for (int j = 0; j < i - 1; j++) {
        if (rev(s, j, i - 1, memo)) {
          dp[i]++;
        }
      }
    }
    return dp[n];
  }
};