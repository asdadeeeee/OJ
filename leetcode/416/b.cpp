#include <algorithm>
#include <iostream>
#include <vector>

#include <numeric>
using namespace std;
class Solution {
public:
  bool canPartition(vector<int> &nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 == 1) {
      return false;
    }
    int target = sum / 2;
    int n = nums.size();
    vector<int> dp(target + 1, 0);
    for (int i = 0; i < n; i++) {
      for (int j = target; j >= nums[i]; j--) {
        dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
      }
    }
    return dp[target] == target;
  }
};