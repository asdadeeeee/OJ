#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;
class Solution {
public:
  int findKthLargest(vector<int> &nums, int k) {
    k_ = nums.size() - k;
    return sort(nums, 0, nums.size() - 1);
  }
  int sort(vector<int> &nums, int begin, int end) {
    if (begin == end) {
      return nums[k_];
    }
    int r = rand() % (end - begin + 1) + begin;
    swap(nums[r], nums[begin]);
    int temp = nums[begin];
    int ptr1 = begin - 1;
    int ptr2 = end + 1;
    while (ptr1 < ptr2) {
      do {
        ptr1++;
      } while (nums[ptr1] < temp);
      do {
        ptr2--;
      } while (nums[ptr2] > temp);
      if (ptr1 < ptr2) {
        swap(nums[ptr1], nums[ptr2]);
      }
    }
    if (k_ <= ptr2) {
      return sort(nums, begin, ptr2);
    }
    return sort(nums, ptr2 + 1, end);
  }

  int k_;
};