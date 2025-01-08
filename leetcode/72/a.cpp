#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

class Solution {

public:
  int minDistance(string word1, string word2) {
    int s1 = word1.size();
    int s2 = word2.size();
    memset(p, -1, sizeof(p));
    return dp(word1, word2, s1 - 1, s2 - 1);
  }
  inline int dp(string &word1, string &word2, int i, int j) {
    if (i < 0) {
      return j + 1;
    }
    if (j < 0) {
      return i + 1;
    }
    if (p[i][j] != -1) {
      return p[i][j];
    }
    if (word1[i] == word2[j]) {
      p[i][j] = dp(word1, word2, i - 1, j - 1);
      return p[i][j];
    }
    int min_ = 0x3f3f3f3f;
    for (int k = 0; k < 3; k++) {
      switch (k) {
      case 0: {
        min_ = min(min_, dp(word1, word2, i - 1, j) + 1);
      }
      case 1: {
        min_ = min(min_, dp(word1, word2, i - 1, j - 1) + 1);
      }
      case 2: {
        min_ = min(min_, dp(word1, word2, i, j - 1) + 1);
      }
      }
    }
    p[i][j] = min_;
    return p[i][j];
  }

  int p[501][501];
};