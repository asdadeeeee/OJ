#include <cstring>
#include <memory>
#include <string.h>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
  vector<int> sortArray(vector<int> &nums) {
    temp.resize(nums.size());
    sort(nums, 0, nums.size() - 1);
    return nums;
  }

  void sort(vector<int> &nums, int begin, int end) {
    if (begin >= end) {
      return;
    }
    int mid = begin + (end - begin) / 2;
    sort(nums, begin, mid);
    sort(nums, mid + 1, end);
    merge(nums, begin, mid, end);
  }

  void merge(vector<int> &nums, int begin, int mid, int end) {
    // memcpy(temp.data(), nums.data(), temp.size() * sizeof(int));
    int ptr1 = begin;
    int ptr2 = mid + 1;
    int count = 0;
    while (ptr1 <= mid && ptr2 <= end) {
      if (nums[ptr1] <= nums[ptr2]) {
        temp[count++] = nums[ptr1++];
      } else {
        temp[count++] = nums[ptr2++];
      }
    }
    while (ptr1 <= mid) {
      temp[count++] = nums[ptr1++];
    }
    while (ptr2 <= end) {
      temp[count++] = nums[ptr2++];
    }
    for (int i = 0; i < end - begin + 1; ++i) {
      nums[i + begin] = temp[i];
    }
    // for (int p = begin; p <= end; p++) {
    //   if (ptr1 == mid + 1) {
    //     nums[p] = temp[ptr2++];
    //   } else if (ptr2 == end + 1) {
    //     nums[p] = temp[ptr1++];
    //   } else if (temp[ptr1] <= temp[ptr2]) {
    //     nums[p] = temp[ptr1++];
    //   } else {
    //     nums[p] = temp[ptr2++];
    //   }
    // }
  }

  vector<int> temp;
};