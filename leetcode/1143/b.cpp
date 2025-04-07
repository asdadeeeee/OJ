#include <algorithm>
#include <cstring>
#include <ios>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
  int longestCommonSubsequence(string text1, string text2) {
    int n = text1.length();
    int m = text2.length();
    vector<int> dp(m + 1, 0);
    for (int i = 0; i < n; i++) {
      int leftup = dp[0];
      for (int j = 1; j <= m; j++) {
        int temp = dp[j];
        if (text1[i] == text2[j - 1]) {
          dp[j] = leftup + 1;
        } else {
          dp[j] = max(dp[j - 1], dp[j]);
        }
        leftup = temp;
      }
    }
    return dp[m];
  }
};
int main() {
  Solution so;
  so.longestCommonSubsequence("abcde", "ace");
}