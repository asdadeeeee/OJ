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
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= num; i++) {
      int count_zero = 0;
      int count_one = 0;
      getcount(strs[i - 1], count_zero, count_one);
      for (int j = m; j >= count_zero; j--) {
        for (int k = n; k >= count_one; k--) {
          dp[j][k] = max(dp[j][k], dp[j - count_zero][k - count_one] + 1);
        }
      }
    }
    return dp[m][n];
  }
};