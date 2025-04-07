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
  int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2) {
    int n = nums1.size();
    int m = nums2.size();
    vector<int> dp(m + 1, 0);
    for (int i = 0; i < n; i++) {
      int temp = dp[0];
      for (int j = 1; j <= m; j++) {
        int leftup = dp[j];
        if (nums1[i] == nums2[j - 1]) {
          dp[j] = temp + 1;
        } else {
          dp[j] = max(dp[j - 1], dp[j]);
        }
        temp = leftup;
      }
    }
    return dp[m];
  }
};
