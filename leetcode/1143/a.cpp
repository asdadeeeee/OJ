#include <algorithm>
#include <cstring>
#include <ios>
#include <iostream>
#include <numeric>
#include <string>
using namespace std;
class Solution {
public:
  int longestCommonSubsequence(string text1, string text2) {
    int s1 = text1.length();
    int s2 = text2.length();
    int p[s2 + 1];
    memset(p, 0, sizeof(p));
    int leftup = 0;
    for (int i = 1; i <= s1; i++) {
      leftup = p[0];

      for (int j = 1; j <= s2; j++) {
        int temp = p[j];
        if (text1[i - 1] == text2[j - 1]) {
          p[j] = leftup + 1;
        } else {
          p[j] = max(p[j], p[j - 1]);
        }
        leftup = temp;
      }
    }
    return p[s2];
  }
};