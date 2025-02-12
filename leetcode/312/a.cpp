#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
  int maxCoins(vector<int> &nums) {
    int n = nums.size();

    vector<int> num(n + 2, 1);
    for (int i = 1; i <= n; i++) {
      num[i] = nums[i - 1];
    }

    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

    for (int i = n; i >= 0; i--) {
      for (int j = i + 1; j <= n + 1; j++) {
        for (int k = i + 1; k < j; k++) {
          dp[i][j] =
              max(dp[i][j], dp[i][k] + dp[k][j] + num[i] * num[k] * num[j]);
        }
      }
    }
    return dp[0][n + 1];
  }
};