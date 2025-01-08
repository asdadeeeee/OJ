#include <vector>
using namespace std;
class Solution {
public:
  int lengthOfLIS(vector<int> &nums) { return func(nums); }

  inline int func(vector<int> &nums) {
    int n = nums.size();
    int ans = 0;
    int dp[2501];
    for (int i = 0; i < n; i++) {
      dp[i] = 1;
      for (int j = 0; j < i; j++) {
        if (nums[j] < nums[i]) {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }
      ans = max(dp[i], ans);
    }
    return ans;
  }
};