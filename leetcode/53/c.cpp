#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int n = nums.size();
    vector<int> dp(n + 1, 0);
    int m = -0x3f3f3f3f;
    for (int i = 1; i < n + 1; i++) {
      dp[i] = max(nums[i - 1], dp[i - 1] + nums[i - 1]);
      m = max(dp[i], m);
    }
    return m;
  }
};