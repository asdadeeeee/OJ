#include <vector>
using namespace std;
class Solution {
public:
  void moveZeroes(vector<int> &nums) {
    int n = nums.size();
    int ptr1 = 0;
    while (ptr1 < n && nums[ptr1] != 0) {
      ptr1++;
    }
    int ptr2 = ptr1 + 1;
    while (ptr2 < n) {
      if (nums[ptr2] != 0) {
        swap(nums[ptr1], nums[ptr2]);
        while (nums[ptr1] != 0) {
          ptr1++;
        }
      }
      ptr2++;
    }
  }
};