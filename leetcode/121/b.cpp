#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;
class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int n = prices.size();
    vector<pair<int, int>> dp(n, {0, 0});
    dp[0].first = -prices[0];
    dp[0].second = 0;
    for (int i = 1; i < n; i++) {
      dp[i].first = max(dp[i - 1].first, -prices[i]);
      dp[i].second = max(dp[i - 1].second, prices[i] + dp[i - 1].first);
    }
    return dp[n - 1].second;
  }
};