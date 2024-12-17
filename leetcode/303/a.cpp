#include <iostream>
#include <vector>
using namespace std;
class NumArray {
public:
  vector<int> nums_;
  vector<int> sums_;
  NumArray(vector<int> &nums) {
    nums_ = nums;
    sums_.resize(nums.size());
    for (int i = 0; i < nums.size(); i++) {
      sums_[i] = i > 0 ? sums_[i - 1] + nums[i] : nums[i];
    }
  }

  int sumRange(int left, int right) {
    return sums_[right] - sums_[left] + nums_[left];
  }
};