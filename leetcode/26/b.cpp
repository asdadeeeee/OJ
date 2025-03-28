#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    int size = nums.size();
    if (size < 2) {
      return size;
    }
    int ptr1 = 1;
    int ptr2 = 1;
    while (ptr2 < size) {
      if (nums[ptr2] != nums[ptr2 - 1]) {
        nums[ptr1] = nums[ptr2];
        ptr1++;
      }
      ptr2++;
    }
    return ptr1;
  }
};