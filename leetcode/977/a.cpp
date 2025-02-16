#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;
class Solution {
public:
  vector<int> sortedSquares(vector<int> &nums) {
    vector<int> ans;

    int n = nums.size();
    int left = 0;
    int right = n - 1;
    if (n == 0) {
      return ans;
    }
    int tmin = 0x3f3f3f3f;
    int min_ptr = 0;
    for (int i = 0; i < n; i++) {
      if (abs(nums[i]) < tmin) {
        tmin = abs(nums[i]);
        min_ptr = i;
      }
    }
    if (min_ptr == right) {
      for (int i = right; i >= 0; i--) {
        ans.emplace_back(nums[i] * nums[i]);
      }
    } else if (min_ptr == left) {
      for (int i = left; i <= right; i++) {
        ans.emplace_back(nums[i] * nums[i]);
      }
    } else {
      int ptr1 = 0;
      int ptr2 = 0;

        ptr1 = min_ptr - 1;
        ptr2 = min_ptr + 1;
        int temp = nums[min_ptr];
        ans.emplace_back(temp * temp);
      
      while (ptr1 >= left && ptr2 <= right) {
        int temp;
        if (abs(nums[ptr1]) <= abs(nums[ptr2])) {
          temp = nums[ptr1];
          ptr1--;
        } else {
          temp = nums[ptr2];
          ptr2++;
        }
        ans.emplace_back(temp * temp);
      }
      while (ptr1 >= left) {
        int temp;
        temp = nums[ptr1];
        ptr1--;
        ans.emplace_back(temp * temp);
      }
      while (ptr2 <= right) {
        int temp;
        temp = nums[ptr2];
        ptr2++;
        ans.emplace_back(temp * temp);
      }
    }

    return ans;
  }
};