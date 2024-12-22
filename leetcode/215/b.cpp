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
    if (begin >= end) {
      return nums[begin];
    }
    int p = partition(nums, begin, end);
    if (p == k_) {
      return nums[p];
    } else if (p > k_) {
      return sort(nums, begin, p - 1);
    } else if (p < k_) {
      return sort(nums, p + 1, end);
    }
    return -1;
  }
  int partition(vector<int> &nums, int begin, int end) {
    // int r = rand() % (end - begin) + begin;
    // swap(nums[begin], nums[r]);
    int temp = nums[begin];
    int ptr1 = begin + 1;
    int ptr2 = end;
    while (ptr1 <= ptr2) {
      while (ptr1 < end && nums[ptr1] <= temp) {
        ptr1++;
      }
      while (ptr2 > begin && nums[ptr2] > temp) {
        ptr2--;
      }
      if (ptr1 >= ptr2) {
        break;
      }
      swap(nums[ptr1], nums[ptr2]);
    }
    swap(nums[begin], nums[ptr2]);
    return ptr2;
  }

  int k_;
};

int main() {
  vector<int> nums = {3, 2, 1, 5, 6, 4};
  Solution so;
  so.findKthLargest(nums, 2);
}