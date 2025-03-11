#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int ans = -0x3f3f3f3f;
    int n = nums.size();
    int res = 0;
    for (int i = 0; i < n; i++) {
      res += nums[i];
      ans = max(res, ans);
      if (res < 0) {
        res = 0;
      }
    }
    return ans;
  }
};