#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int inf = 0x3f3f3f3f;
class Solution {
public:
  int minFallingPathSum(vector<vector<int>> &matrix) {
    vector<vector<int>> dp;
    dp.resize(2, vector<int>(matrix[0].size(), inf));
    int ans = inf;
    for (int i = 0; i <= matrix.size(); i++) {
      for (int j = 0; j < matrix[0].size(); j++) {
        if (i == 0) {
          dp[i][j] = matrix[i][j];
        } else if (i > 0 && i < matrix.size()) {
          int min_ = inf;
          for (int k = -1; k < 2; k++) {
            if (j + k < 0 || j + k >= matrix[0].size()) {
              continue;
            }
            min_ = min(dp[(i - 1) % 2][j + k], min_);
          }
          dp[i % 2][j] = min_ + matrix[i][j];
        } else if (i == matrix.size()) {
          ans = min(ans, dp[(i - 1) % 2][j]);
        }
      }
    }
    return ans;
  }
};

int main() {
  vector<vector<int>> nums = {{2, 1, 3}, {6, 5, 4}, {7, 8, 9}};
  Solution so;
  cout << so.minFallingPathSum(nums);
}