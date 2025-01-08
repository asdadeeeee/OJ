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
    dp.resize(matrix.size(), vector<int>(matrix[0].size(), inf));
    int min_;
    for (int i = 0; i < matrix[0].size(); i++) {
      min_ = min(func(matrix, matrix.size() - 1, i, dp), min_);
    }
    return min_;
  }
  int func(vector<vector<int>> &matrix, int i, int j, vector<vector<int>> &dp) {
    if (i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size()) {
      return inf;
    }
    if (i == 0) {
      dp[i][j] = matrix[i][j];
      return dp[i][j];
    }
    if (dp[i][j] != inf) {
      return dp[i][j];
    }
    int min_ = inf;
    for (int k = -1; k < 2; k++) {
      min_ = min(func(matrix, i - 1, j + k, dp), min_);
    }
    dp[i][j] = matrix[i][j] + min_;
    return dp[i][j];
  }
};

int main() {
  vector<vector<int>> nums = {{2, 1, 3}, {6, 5, 4}, {7, 8, 9}};
  Solution so;
  cout << so.minFallingPathSum(nums);
}