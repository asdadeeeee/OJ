#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;
class Solution {
public:
  int maxProfit(int k, vector<int> &prices) {
    vector<int> dp(2 * k, 0);
    for (int i = 0; i < 2 * k; i++) {
      if (i % 2 == 0) {
        dp[i] = -prices[0];
      } else {
        dp[i] = 0;
      }
    }
    int n = prices.size();
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < 2 * k; j++) {
        if (j == 0) {
          dp[j] = max(dp[j], -prices[i]);
        } else if (j % 2 == 1) {
          dp[j] = max(dp[j], dp[j - 1] + prices[i]);
        } else {
          dp[j] = max(dp[j], dp[j - 1] - prices[i]);
        }
      }
    }
    return dp[2 * k - 1];
  }
};

int main() {
  vector<int> p = {2, 4, 1};
  Solution so;
  cout << so.maxProfit(2, p);
}