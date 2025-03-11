#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;
class Solution {
public:
  int largestSumAfterKNegations(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end());
    int ptr = 0;
    int n = nums.size();
    while (k > 0) {
      if (nums[ptr] < 0) {
        nums[ptr] = -nums[ptr];
        ptr++;
        ptr = ptr % n;
        k--;
      } else if (nums[ptr] > 0) {
        if (k % 2 == 1) {
          sort(nums.begin(), nums.end());
          nums[0] = -nums[0];
          break;
        } else {
          break;
        }
      } else {
        break;
      }
    }
    return accumulate(nums.begin(), nums.end(), 0);
  }
};
int main() {
  Solution so;
  vector<int> nums = {-4, -2, -3};
  so.largestSumAfterKNegations(nums, 4);
}