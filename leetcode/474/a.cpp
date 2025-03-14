#include <string>
#include <vector>
using namespace std;
class Solution {
public:
  inline void getcount(const string &s, int &count_zero, int &count_one) {
    int n = s.size();
    count_zero = 0;
    count_one = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '0') {
        count_zero++;
      } else {
        count_one++;
      }
    }
  }
  int findMaxForm(vector<string> &strs, int m, int n) {
    int num = strs.size();
    vector<vector<vector<int>>> dp(
        num + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
    for (int i = 1; i <= num; i++) {
      int count_zero = 0;
      int count_one = 0;
      getcount(strs[i - 1], count_zero, count_one);
      for (int j = 0; j <= m; j++) {
        if (j < count_zero) {
          for (int k = 0; k <= n; k++) {
            dp[i][j][k] = dp[i - 1][j][k];
          }
        } else {
          for (int k = 0; k <= n; k++) {
            if (k < count_one) {
              dp[i][j][k] = dp[i - 1][j][k];
            } else {
              dp[i][j][k] = max(dp[i - 1][j][k],
                                dp[i - 1][j - count_zero][k - count_one] + 1);
            }
          }
        }
      }
    }
    return dp[num][m][n];
  }
};