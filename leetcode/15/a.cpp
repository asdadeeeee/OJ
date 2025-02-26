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
    while (ptr < n - 1) {
      if (nums[ptr] > 0) {
        break;
      }
      if (ptr > 0 && nums[ptr] == nums[ptr - 1]) {
        ptr++;
        continue;
      }
      int left = ptr + 1;
      int right = n - 1;
      while (left < right) {
        int a = nums[ptr];
        int b = nums[left];
        int c = nums[right];
        if (a + b + c > 0) {
          right--;
        } else if (a + b + c < 0) {
          left++;
        } else {
          ans.emplace_back(vector<int>{nums[ptr], nums[left], nums[right]});
          while (left < right && nums[left + 1] == nums[left]) {
            left++;
          }
          while (left < right && nums[right - 1] == nums[right]) {
            right--;
          }
          left++;
          right--;
        }
      }
      ptr++;
    }
    return ans;
  }
};
int main() {
  vector<int> nums = {-1, 0, 1, 2, -1, -4};
  Solution so;
  so.threeSum(nums);
}