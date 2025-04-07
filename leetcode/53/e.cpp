#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
  int maxSubArray(vector<int> &nums) {

    int ans = -0x3f3f3f3f;
    int temp = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      if (temp + nums[i] < 0) {
        temp = nums[i];
      } else {
        if (temp < 0) {
          temp = nums[i];
        } else {
          temp += nums[i];
        }
      }
      ans = max(ans, temp);
    }
    return ans;
  }
};
