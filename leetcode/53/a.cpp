#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      dp[i] = max(nums[i], dp[i - 1] + nums[i]);
    }
    int ans = -0x3f3f3f3f;
    for (int i = 0; i < nums.size(); i++) {
      ans = max(dp[i], ans);
    }
    return ans;
  }
};