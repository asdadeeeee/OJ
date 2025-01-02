#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  int dx[4] = {0, 0, 1, -1};
  int dy[4] = {1, -1, 0, 0};
  inline bool bound(int n, int m, int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
  }
  int maxAreaOfIsland(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 1) {
          int temp = 0;
          dfs(n, m, i, j, grid, temp);
          ans = max(ans, temp);
        }
      }
    }
    return ans;
  }
  void dfs(int n, int m, int curx, int cury, vector<vector<int>> &grid,
           int &temp) {
    grid[curx][cury] = 0;
    temp++;
    for (int i = 0; i < 4; i++) {
      int nx = curx + dx[i];
      int ny = cury + dy[i];
      if (bound(n, m, nx, ny) && grid[nx][ny] == 1) {
        dfs(n, m, nx, ny, grid, temp);
      }
    }
  }
};