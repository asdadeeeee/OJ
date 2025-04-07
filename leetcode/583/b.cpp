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
  int minDistance(string word1, string word2) {
    int n = word1.length();
    int m = word2.length();
    vector<int> dp(m + 1, 0);
    for (int i = 0; i <= m; i++) {
      dp[i] = i;
    }
    for (int i = 0; i < n; i++) {
      int temp = dp[0];
      for (int j = 0; j <= m; j++) {
        int leftup = dp[j];
        if (j == 0) {
          dp[j]++;
        } else {
          if (word1[i] == word2[j - 1]) {
            dp[j] = temp;
          } else {
            dp[j] = min(dp[j - 1], dp[j]) + 1;
          }
        }
        temp = leftup;
      }
    }
    return dp[m];
  }
};