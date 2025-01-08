#include <algorithm>
#include <cstring>
#include <string.h>
#include <vector>
using namespace std;
// 迭代dp
const int inf = 0x3f3f3f3f;
class Solution {
public:
  int coinChange(vector<int> &coins, int amount) {
    if (amount == 0) {
      return 0;
    }
    int dp[amount + 1];
    memset(dp, inf, sizeof(dp));
    dp[0] = 0;
    for (int i = 1; i <= amount; i++) {
      for (int j = 0; j < coins.size(); j++) {
        if (i - coins[j] < 0) {
          continue;
        }
        dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
      }
    }
    return dp[amount] == inf ? -1 : dp[amount];
  }
};
