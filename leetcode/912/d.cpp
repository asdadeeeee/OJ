#include <cstdlib>
#include <cstring>
#include <iterator>
#include <memory>
#include <ranges>
#include <string.h>
#include <string>
#include <type_traits>
#include <vector>
using namespace std;
class Solution {
public:
  vector<int> sortArray(vector<int> &nums) {
    sort(nums, 0, nums.size() - 1);
    return nums;
  }

  void sort(vector<int> &nums, int begin, int end) {
    if (begin >= end) {
      return;
    }
    int p = partition(nums, begin, end);
    sort(nums, begin, p);
    sort(nums, p + 1, end);
  }
  int partition(vector<int> &nums, int begin, int end) {
    int temp_idx = rand() % (end - begin + 1) + begin;
    swap(nums[temp_idx], nums[begin]);
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
    return ptr2;
  }
};