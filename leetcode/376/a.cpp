#include <vector>
using namespace std;
class Solution {
public:
  int wiggleMaxLength(vector<int> &nums) {
    int n = nums.size();
    if (n <= 1) {
      return n;
    }
    if (n == 2) {
      if (nums[0] != nums[1]) {
        return 2;
      }
      return 1;
    }
    int s = 0;
    int i = 1;
    int ans = 1;
    int prediff = 0;
    while (i < n) {
      int diff = nums[i] - nums[i - 1];
      if (diff > 0) {
        if (prediff <= 0) {
          ans++;
        }
        prediff = diff;
      } else if (diff < 0) {
        if (prediff >= 0) {
          ans++;
        }
        prediff = diff;
      } 
      i++;
    }
    return ans;
  }
};