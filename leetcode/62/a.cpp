#include <vector>
using namespace std;
class Solution {
public:
  int uniquePaths(int m, int n) {
    vector<vector<int>> path(m + 1, vector<int>(n + 1, 1));

    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        if (i == 1 || j == 1) {
          path[i][j] = 1;
          continue;
        }
        path[i][j] = path[i - 1][j] + path[i][j - 1];
      }
    }
    return path[m][n];
  }
};