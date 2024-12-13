#include <vector>

using namespace std;
class Solution {
public:
  int left_bound(vector<int> &nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] >= target) {
        right = mid - 1;
      } else if (nums[mid] < target) {
        left = mid + 1;
      }
    }
    if (left >= nums.size()) {
      return -1;
    }
    return left;
  }

  int right_bound(vector<int> &nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] > target) {
        right = mid - 1;
      } else if (nums[mid] <= target) {
        left = mid + 1;
      }
    }
    if (right < 0) {
      return -1;
    }
    return right;
  }

  vector<int> searchRange(vector<int> &nums, int target) {
    int ansL = -1;
    int ansR = -1;
    int L = left_bound(nums, target);
    int R = right_bound(nums, target);
    if (L != -1 && nums[L] == target) {
      ansL = L;
    }
    if (R != -1 && nums[R] == target) {
      ansR = R;
    }
    return {ansL, ansR};
  }
};
