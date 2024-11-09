#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
// 迭代dp
// class Solution {
// public:
//   int coinChange(vector<int> &coins, int amount) {
//     if (amount == 0) {
//       return 0;
//     }
//     int dp[amount + 1];
//     dp[0] = 0;
//     for (int i = 1; i <= amount; i++) {
//       int min = 0x3f3f3f3f;
//       for (int j = 0; j < coins.size(); j++) {
//         if (i - coins.at(j) >= 0 && dp[i - coins.at(j)] < min) {
//           min = dp[i - coins.at(j)];
//         }
//       }
//       dp[i] = min + 1;
//     }
//     return dp[amount] == 0x3f3f3f3f + 1 ? -1 : dp[amount];
//   }
// };

// 备忘录递归（分解）
class Solution {
public:
  int coinChange(vector<int> &coins, int amount) {
    memo.resize(amount + 1);
    int ans = dp(coins, amount, memo);
    return ans;
  }

  int dp(vector<int> &coins, int amount, vector<int> &memo) {
    if (amount == 0) {
      return 0;
    }
    if (amount < 0) {
      return -1;
    }
    if (memo[amount] != 0) {
      return memo[amount];
    }
    int res = 0x3f3f3f3f;
    for (const int coin : coins) {
      int sub_res = dp(coins, amount - coin, memo);
      if (sub_res == -1) {
        continue;
      }
      res = min(res, sub_res + 1);
    }
    memo[amount] = res == 0x3f3f3f3f ? -1 : res;
    return memo[amount];
  }

  vector<int> memo;
};