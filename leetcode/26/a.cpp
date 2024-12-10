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
    int cur_k = size;
    auto ptr1 = 0;
    auto ptr2 = 1;

    while (ptr2 < cur_k) {
      while (ptr2 < cur_k && nums[ptr2] == nums[ptr1]) {
        for (int i = ptr2; i < cur_k - 1; i++) {
          nums[i] = nums[i + 1];
        }
        cur_k--;
      }
      ptr1++;
      ptr2++;
    }
    return cur_k;
  }
};

int main() {
  vector<int> nums = {1, 1, 2};
  Solution sol;
  int res = sol.removeDuplicates(nums);
  cout << res;
}