#include <algorithm>
#include <iostream>
#include <vector>

#include <numeric>
using namespace std;

class Solution {
public:
  //   inline bool collect(vector<int> &nums,int sum) {

  //   }
  bool canPartition(vector<int> &nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    // int sum = 0;
    // for (auto t : nums) {
    //   sum += t;
    // }
    if (sum % 2 != 0) {
      return false;
    }
    sum = sum / 2;
    int n = nums.size();
    vector<int> dp(sum + 1, 0);
    for (int i = 0; i < n; i++) {
      for (int j = sum; j >= 1; j--) {
        if (j >= nums[i]) {
          dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
        }
      }
    }
    return dp[sum] == sum;
  }
};

int main() {
  vector<int> nums = {1, 5, 11, 5};
  Solution so;
  cout << so.canPartition(nums);
}