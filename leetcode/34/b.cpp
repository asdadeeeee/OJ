#include <vector>
using namespace std;
class Solution {
public:
  int lower_bound(vector<int> &nums, int target) {
    int n = nums.size();
    int left = 0;
    int right = n - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] == target) {
        right = mid - 1;
      } else if (nums[mid] < target) {
        left = mid + 1;
      } else if (nums[mid] > target) {
        right = mid - 1;
      }
    }
    return left;
  }

  int upper_bound(vector<int> &nums, int target) {
    int n = nums.size();
    int left = 0;
    int right = n - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] == target) {
        left = mid + 1;
      } else if (nums[mid] < target) {
        left = mid + 1;
      } else if (nums[mid] > target) {
        right = mid - 1;
      }
    }
    return right;
  }
  vector<int> searchRange(vector<int> &nums, int target) {
    int n = nums.size();
    int left = lower_bound(nums, target);
    int right = upper_bound(nums, target);
    if (left == n || nums[left] != target) {
      left = -1;
    }
    if (right == -1 || nums[right] != target) {
      right = -1;
    }
    vector<int> ans;
    ans.emplace_back(left);
    ans.emplace_back(right);
    return ans;
  }
};