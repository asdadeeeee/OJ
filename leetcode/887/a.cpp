#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
  int superEggDrop(int k, int n) {
    vector<vector<int>> me(k + 1, vector<int>(n + 1, -1));
    return dp(k, n, me);
  }

  inline int dp(int k, int n, vector<vector<int>> &memo) {
    if (k == 1) {
      return n;
    }
    if (n == 0) {
      return 0;
    }
    if (memo[k][n] != -1) {
      return memo[k][n];
    }

    int res = 0x3f3f3f3f;
    int left = 1;
    int right = n;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      int broke = dp(k - 1, mid - 1, memo);
      int un_broke = dp(k, n - mid, memo);
      if (broke > un_broke) {
        right = mid - 1;
        res = min(res, broke + 1);
      } else if (broke < un_broke) {
        left = mid + 1;
        res = min(res, un_broke + 1);
      } else {
        res = min(res, broke + 1);
        break;
      }
    }
    memo[k][n] = res;
    return res;
  };
};