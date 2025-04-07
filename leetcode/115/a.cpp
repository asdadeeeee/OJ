#include <algorithm>
#include <cmath>
#include <cstring>
#include <ios>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
  int numDistinct(string s, string t) {
    int n = s.length();
    int m = t.length();
    vector<int> dp(n + 1, 1);
    for (int i = 0; i < m; i++) {
      int temp = dp[0];
      dp[0] = 0;
      for (int j = 1; j <= n; j++) {
        int leftup = dp[j];
        if (j <= i) {
          dp[j] = 0;
        } else {
          if (t[i] == s[j - 1]) {
            dp[j] = (temp + dp[j - 1]) % (int)(pow(10, 9) + 7);
          } else {
            dp[j] = dp[j - 1];
          }
        }
        temp = leftup;
      }
    }
    return dp[n];
  }
};