#include <vector>
using namespace std;
class Solution {
public:
  bool canJump(vector<int> &nums) {
    int n = nums.size();
    int c = 0;
    for (int i = 0; i <= c; i++) {
      c = max(i + nums[i], c);
      if (c >= n - 1) {
        return true;
      }
    }
    return false;
  }
};