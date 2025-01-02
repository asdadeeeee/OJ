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
  int closedIsland(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    int cnt = 0;

    for (int i = 0; i < n; i++) {
      if (grid[i][0] == 0) {
        dfs(n, m, i, 0, grid);
      }
      if (grid[i][m - 1] == 0) {
        dfs(n, m, i, m - 1, grid);
      }
    }
    for (int j = 0; j < m; j++) {
      if (grid[0][j] == 0) {
        dfs(n, m, 0, j, grid);
      }
      if (grid[n - 1][j] == 0) {
        dfs(n, m, n - 1, j, grid);
      }
    }
    for (int i = 1; i < n - 1; i++) {
      for (int j = 1; j < m - 1; j++) {
        if (grid[i][j] == 0) {
          cnt++;
          dfs(n, m, i, j, grid);
        }
      }
    }
    return cnt;
  }

  void dfs(int n, int m, int curx, int cury, vector<vector<int>> &grid) {
    grid[curx][cury] = 1;
    for (int i = 0; i < 4; i++) {
      int nx = curx + dx[i];
      int ny = cury + dy[i];
      if (bound(n, m, nx, ny) && grid[nx][ny] == 0) {
        dfs(n, m, nx, ny, grid);
      }
    }
  }
};
