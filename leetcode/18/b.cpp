#include <algorithm>
#include <iterator>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
  vector<vector<int>> fourSum(vector<int> &nums, int target) {
    int n = nums.size();
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    int ptr1 = 0;
    int ptr2 = 1;
    for (ptr1 = 0; ptr1 < n - 3; ptr1++) {
      if (nums[ptr1] >= target && nums[ptr1] > 0) {
        break;
      }
      if (ptr1 > 0 && nums[ptr1] == nums[ptr1 - 1]) {
        continue;
      }
      for (ptr2 = ptr1 + 1; ptr2 < n; ptr2++) {
        if (nums[ptr1] + nums[ptr2] >= target && nums[ptr1] + nums[ptr2] > 0) {
          break;
        }
        if (ptr2 > ptr1 + 1 && nums[ptr2] == nums[ptr2 - 1]) {
          continue;
        }
        int left = ptr2 + 1;
        int right = n - 1;
        while (left < right) {
          long temp = 0;
          int a = nums[ptr1];
          int b = nums[left];
          int c = nums[right];
          int d = nums[ptr2];
          temp = (long)a + b + c + d;
          if (temp > target) {
            right--;
          } else if (temp < target) {
            left++;
          } else {
            ans.emplace_back(vector<int>{a, b, c, d});
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
      }
    }
    return ans;
  }
};
