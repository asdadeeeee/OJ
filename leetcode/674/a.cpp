#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
  int findLengthOfLCIS(vector<int> &nums) {
    int n = nums.size();
    int temp = 1;
    int ans = 1;
    for (int i = 1; i < n; i++) {
      if (nums[i] > nums[i - 1]) {
        temp++;
        ans = max(ans, temp);
      } else {
        temp = 1;
      }
    }
    return ans;
  }
};