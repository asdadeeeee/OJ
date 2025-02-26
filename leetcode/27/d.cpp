#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  int removeElement(vector<int> &nums, int val) {
    int n = nums.size();
    int left = 0;
    int right = n - 1;
    while (left < n && nums[left] != val) {
      left++;
    }
    while (right >= 0 && nums[right] == val) {
      right--;
    }
    while (left < right) {
      while (left < right && nums[left] != val) {
        left++;
      }
      while (left < right && nums[right] == val) {
        right--;
      }
      if (left < n && right >= 0) {
        swap(nums[left], nums[right]);
      }
    }
    return left;
  }
};