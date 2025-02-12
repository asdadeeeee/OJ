#include <vector>
using namespace std;
class Solution {
public:
  int removeElement(vector<int> &nums, int val) {
    int n = nums.size();

    int ptr = n - 1;
    while (ptr >= 0 && nums[ptr] == val) {
      ptr--;
    }
    for (int i = 0; i < n && i <= ptr; i++) {
      if (nums[i] == val) {
        swap(nums[i], nums[ptr]);
        ptr--;
        while (ptr >= 0 && nums[ptr] == val) {
          ptr--;
        }
      }
    }
    return ptr + 1;
  }
};