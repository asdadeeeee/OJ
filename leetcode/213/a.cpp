#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  int rob(vector<int> &nums) {
    int n = nums.size();
    if (n == 1) {
      return nums[0];
    }
    if (n == 2) {
      return max(nums[0], nums[1]);
    }
    int res0 = robsub(0, n - 2, nums);
    int res1 = robsub(1, n - 1, nums);
    return max(res0, res1);
  }

  int robsub(int start, int end, vector<int> &nums) {
    int n = end - start + 1;
    if (n == 1) {
      return nums[start];
    }
    if (n == 2) {
      return max(nums[start], nums[end]);
    }
    vector<int> dp(n + 1, 0);
    dp[0] = nums[start];
    dp[1] = max(nums[start], nums[start + 1]);
    for (int i = 2; i < n; i++) {
      dp[i] = max(dp[i - 1], dp[i - 2] + nums[start + i]);
    }
    return dp[n - 1];
  }
};