#include <algorithm>
#include <cstring>
#include <ios>
#include <iostream>
#include <numeric>
#include <string>
using namespace std;

class Solution {

public:
  int minDistance(string word1, string word2) {
    int s1 = word1.size();
    int s2 = word2.size();
    int dp[s2 + 1];
    // memset(dp, 0, sizeof(dp));
    // for (int i = 0; i <= s2; i++) {
    //   dp[i] = i;
    // }
    std::iota(dp, dp + s2 + 1, 0);
    int leftup = 0;
    for (int i = 1; i <= s1; i++) {
      leftup = dp[0];
      dp[0] = i;
      for (int j = 1; j <= s2; j++) {
        int temp = dp[j];
        if (word1[i - 1] == word2[j - 1]) {
          dp[j] = leftup;
        } else {
          dp[j] = min({leftup, dp[j], dp[j - 1]}) + 1;
        }
        leftup = temp;
      }
    }
    return dp[s2];
  }
};

int main() {
  Solution so;
  cout << so.minDistance("mart", "karma");
}