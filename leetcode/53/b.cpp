#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int dp_1 = nums[0];
    int dp_0 = 0;
    int ans = dp_1;
    for (int i = 1; i < nums.size(); i++) {
      dp_0 = dp_1;
      dp_1 = max(nums[i], dp_0 + nums[i]);
      ans = max(ans, dp_1);
    }
    return ans;
  }
};