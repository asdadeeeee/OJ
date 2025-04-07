#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <math.h>
#include <vector>

#include <cmath>
#include <cstring>
#include <numeric>
#include <string>
using namespace std;
class Solution {
public:
  inline bool square(int t, vector<bool> &smemo) {
    for (int i = 0; i <= sqrt(t); i++) {
      if (i * i == t) {
        smemo[t] = true;
        return true;
      }
    }
    return false;
  }
  int numSquares(int n) {
    vector<int> dp(n + 1, 0x3f3f3f3f);
    dp[0] = 0;
    vector<bool> smemo(n + 1, false);
    for (int i = 0; i <= n; i++) {
      square(i, smemo);
      for (int j = sqrt(i); j >= 0; j--) {
        if (smemo[j]) {
          dp[i] = min(dp[i], dp[i - j] + 1);
        }
      }
    }
    return dp[n];
  }
};

int main() {
  Solution so;
  so.numSquares(7168);
}