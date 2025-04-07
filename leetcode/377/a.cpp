#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <vector>

#include <cmath>
#include <cstring>
#include <numeric>
#include <string>
using namespace std;
class Solution {
public:
  int combinationSum4(vector<int> &nums, int target) {
    vector<uint64_t> dp(target + 1, 0);
    dp[0] = 1;
    for (int i = 0; i <= target; i++) {
      for (auto num : nums) {
        if (i >= num) {
          dp[i] += dp[i - num];
        }
      }
    }
    return dp[target];
  }
};