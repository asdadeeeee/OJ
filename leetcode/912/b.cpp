#include <cstdlib>
#include <cstring>
#include <memory>
#include <string.h>
#include <string>
#include <type_traits>
#include <vector>
using namespace std;
class Solution {
public:
  vector<int> sortArray(vector<int> &nums) {
    shuffle(nums);
    sort(nums, 0, nums.size() - 1);
    return nums;
  }

  void shuffle(vector<int> &nums) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      int r = rand() % (n - i) + i;
      swap(nums[i], nums[r]);
    }
  }
  void sort(vector<int> &nums, int begin, int end) {
    if (begin >= end) {
      return;
    }
    int p = partition(nums, begin, end);
    sort(nums, begin, p - 1);
    sort(nums, p + 1, end);
  }
  int partition(vector<int> &nums, int begin, int end) {
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
};