#include <algorithm>
#include <iostream>
#include <vector>

#include <numeric>
using namespace std;
class Solution {
public:
  int lastStoneWeightII(vector<int> &stones) {
    int sum = accumulate(stones.begin(), stones.end(), 0);
    int n = stones.size();
    int limit = sum / 2;
    vector<int> dp(limit + 1, 0);
    for (int i = 0; i < n; i++) {
      for (int j = limit; j >= stones[i]; j--) {
        dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
      }
    }
    return abs(sum - dp[limit] * 2);
  }
};