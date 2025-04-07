#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;
class Solution {
public:
  int maxProfit(vector<int> &prices) {
    vector<int> dp(4, 0);
    int n = prices.size();
    dp[0] = -prices[0];
    for (int i = 1; i < n; i++) {
      int temp0 = dp[0];
      int temp1 = dp[1];
      dp[0] = max(dp[0], max(dp[3] - prices[i], dp[2] - prices[i]));
      dp[1] = temp0 + prices[i];
      dp[2] = max(dp[2], dp[3]);
      dp[3] = temp1;
    }
    return max(dp[3], max(dp[1], dp[2]));
  }
};