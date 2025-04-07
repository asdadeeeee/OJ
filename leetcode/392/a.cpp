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
  bool isSubsequence(string s, string t) {
    int n = s.length();
    int m = t.length();
    vector<bool> dp(m + 1, true);
    if (n == 0) {
      return true;
    }
    if (n > m) {
      return false;
    }
    bool leftup = true;
    for (int i = 0; i < n; i++) {
      bool temp = dp[0];
      for (int j = 1; j <= m; j++) {
        leftup = dp[j];
        if (j <= i) {
          dp[j] = false;
        } else {
          if (temp == false) {
            dp[j] = false;
          } else {
            if (j > 1 && dp[j - 1]) {
              dp[j] = true;
            } else {
              if (s[i] == t[j - 1]) {
                dp[j] = true;
              } else {
                dp[j] = false;
              }
            }
          }
        }
        temp = leftup;
      }
    }
    return dp[m];
  }
};
int main() {
  Solution so;
  so.isSubsequence("abc", "ahbgdc");
}