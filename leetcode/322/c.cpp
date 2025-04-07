#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <vector>

#include <cmath>
#include <cstring>
#include <numeric>
#include <string>
using namespace std;

class Solution {
public:
  int coinChange(vector<int> &coins, int amount) {
    sort(coins.begin(), coins.end(), less<>());
    vector<int> dp(amount + 1, 0x3f3f3f3f);
    dp[0] = 0;
    for (int i = 0; i <= amount; i++) {
      for (auto c : coins) {
        if (i >= c) {
          dp[i] = min(dp[i], dp[i - c] + 1);
        }
      }
    }
    return dp[amount] == 0x3f3f3f3f ? -1 : dp[amount];
  }
};