#include <vector>
using namespace std;
class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> path(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        if (obstacleGrid[i - 1][j - 1] == 0) {
          if (i == 1 && j == 1) {
            path[i][j] = 1;
          } else {
            path[i][j] = path[i - 1][j] + path[i][j - 1];
          }
        } else {
          path[i][j] = 0;
        }
      }
    }
    return path[m][n];
  }
};