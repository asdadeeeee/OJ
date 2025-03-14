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
  int change(int amount, vector<int> &coins) {
    int n = coins.size();
    vector<uint64_t> dp(amount + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= amount; j++) {
        if (j >= coins[i - 1]) {
          dp[j] = dp[j] + dp[j - coins[i - 1]];
        }
      }
    }
    return dp[amount];
  }
};