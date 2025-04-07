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
    vector<int> dp(4, 0);
    dp[0] = -prices[0];
    dp[1] = 0;
    dp[2] = -prices[0];
    dp[3] = 0;
    for (int i = 1; i < n; i++) {
      dp[0] = max(dp[0], -prices[i]);
      dp[1] = max(dp[1], dp[0] + prices[i]);
      dp[2] = max(dp[2], dp[1] - prices[i]);
      dp[3] = max(dp[3], dp[2] + prices[i]);
    }
    return dp[3];
  }
};

int main() {
  vector<int> p = {2, 4, 1};
  Solution so;
  cout << so.maxProfit(p);
}