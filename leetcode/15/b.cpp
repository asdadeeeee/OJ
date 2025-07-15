#include <algorithm>
#include <iterator>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int ptr = 0;
    while (ptr <= n - 3) {
      int left = ptr + 1;
      int right = n - 1;
      while (left >= 0 && right <= n - 1 && left < right) {
        int a = nums[ptr];
        int b = nums[left];
        int c = nums[right];
        if (a + b + c > 0) {
          right--;
          while (right >= 0 && nums[right] == nums[right + 1]) {
            right--;
          }
        } else if (a + b + c < 0) {
          left++;
          while (left <= n - 1 && nums[left] == nums[left - 1]) {
            left++;
          }
        } else {
          ans.push_back({a, b, c});
          left++;
          while (left <= n - 1 && nums[left] == nums[left - 1]) {
            left++;
          }
          right--;
          while (right >= 0 && nums[right] == nums[right + 1]) {
            right--;
          }
        }
      }
      ptr++;
      while (ptr <= n - 1 && nums[ptr] == nums[ptr - 1]) {
        ptr++;
      }
    }
    return ans;
  }
};