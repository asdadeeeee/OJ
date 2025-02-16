#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;
class Solution {
public:
  vector<int> sortedSquares(vector<int> &nums) {
    vector<int> ans;
    int n = nums.size();
    ans.resize(n);
    int ans_ptr = n - 1;
    int left = 0;
    int right = n - 1;
    int ptr1 = left;
    int ptr2 = right;
    while (ptr1 <= ptr2) {
      int temp;
      if (abs(nums[ptr1]) >= abs(nums[ptr2])) {
        temp = nums[ptr1];
        ptr1++;
      } else {
        temp = nums[ptr2];
        ptr2--;
      }
      ans[ans_ptr] = temp * temp;
      ans_ptr--;
    }
    return ans;
  }
};