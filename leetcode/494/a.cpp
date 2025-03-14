#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

#include <cmath>
#include <cstring>
#include <numeric>
#include <string>
using namespace std;
class Solution {
public:
  int findTargetSumWays(vector<int> &nums, int target) {
    int n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if ((sum + target) % 2 == 1 || sum < abs(target)) {
      return 0;
    }
    int limit = (sum + target) / 2;
    vector<vector<int>> dp(n + 1, vector<int>(limit + 1, 0));
    int zero_num = 0;
    for (int i = 0; i < n; i++) {
      if (nums[i] == 0) {
        zero_num++;
      }
      dp[i + 1][0] = pow(2, zero_num);
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= limit; j++) {
        if (j < nums[i - 1]) {
          dp[i][j] = dp[i - 1][j];
        } else {
          dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
        }
      }
    }
    return dp[n][limit];
  }
};
int main() {
  Solution so;
  vector<int> nums = {1, 1, 1, 1, 1};
  so.findTargetSumWays(nums, 3);
}