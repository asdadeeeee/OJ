#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

class Solution {

public:
  int minDistance(string word1, string word2) {
    int s1 = word1.size();

    int s2 = word2.size();
    if (s1 == 0) {
      return s2;
    }
    if (s2 == 0) {
      return s1;
    }

    int dp[s1 + 1][s2 + 1];
    dp[0][0] = 0;
    for (int j = 1; j <= s2; j++) {
      dp[0][j] = j;
    }
    for (int i = 1; i <= s1; i++) {
      dp[i][0] = i;
    }
    for (int i = 1; i <= s1; i++) {
      for (int j = 1; j <= s2; j++) {
        if (word1[i - 1] == word2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1];
        } else {
          int min_ = 0x3f3f3f3f;
          for (int k = 0; k < 3; k++) {
            switch (k) {
            case 0: {
              min_ = min(min_, dp[i - 1][j] + 1);
              break;
            }
            case 1: {
              min_ = min(min_, dp[i - 1][j - 1] + 1);
              break;
            }
            case 2: {
              min_ = min(min_, dp[i][j - 1] + 1);
              break;
            }
            }
          }
          dp[i][j] = min_;
        }
      }
    }
    return dp[s1][s2];
  }
};

int main() {
  Solution so;
  cout << so.minDistance("mart", "karma");
}