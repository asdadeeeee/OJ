#include <cstring>
#include <string>
using namespace std;
class Solution {
public:
  bool isMatch(string s, string p) {
    memset(dp, 0, sizeof(dp));
    return func(s, p, 0, 0) == 1 ? true : false;
  }

  int func(const string &s, const string &p, int i, int j) {
    int n = s.size();
    int m = p.size();
    if (i == n && j == m) {
      return 1;
    } else if (i < n && j == m) {
      return -1;
    }
    if (dp[i][j] != 0) {
      return dp[i][j];
    }

    if (((j == m - 1 || ((j < m - 1) && p[j + 1] != '*')) && p[j] != '*')) {
      if (i >= n) {
        dp[i][j] = -1;
        return dp[i][j];
      }
      if ((p[j] == '.' || p[j] == s[i])) {
        dp[i][j] = func(s, p, i + 1, j + 1);
        return dp[i][j];
      }

    } else if (j < m && p[j] == '*') {
      if (p[j - 1] == '.') {
        for (int k = i; k <= n; k++) {

          if (func(s, p, k, j + 1) == 1) {
            dp[i][j] = 1;
            return dp[i][j];
          }
        }
        dp[i][j] = -1;
        return dp[i][j];
      } else {
        for (int k = i; k <= n; k++) {
          if (s[k] != p[j - 1]) {
            dp[i][j] = func(s, p, k, j + 1);
            return dp[i][j];
          } else {
            if (func(s, p, k, j + 1) == 1) {

              dp[i][j] = 1;
              return dp[i][j];
            }
          }
        }
        dp[i][j] = -1;
        return dp[i][j];
      }

    } else {
      dp[i][j] = func(s, p, i, j + 1);
      return dp[i][j];
    }
    dp[i][j] = -1;
    return dp[i][j];
  }

  int dp[21][21];
};