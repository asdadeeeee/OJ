#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int dx[4] = {0, 0, 1, -1};
  int dy[4] = {1, -1, 0, 0};
  inline bool bound(int n, int m, int x, int y) {
    return x >= 1 && x < n - 1 && y >= 1 && y < m - 1;
  }
  int numEnclaves(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (grid[i][0] == 1) {
        dfs(n, m, i, 0, grid, false, cnt);
      }
      if (grid[i][m - 1] == 1) {
        dfs(n, m, i, m - 1, grid, false, cnt);
      }
    }
    for (int j = 0; j < m; j++) {
      if (grid[0][j] == 1) {
        dfs(n, m, 0, j, grid, false, cnt);
      }
      if (grid[n - 1][j] == 1) {
        dfs(n, m, n - 1, j, grid, false, cnt);
      }
    }
    for (int i = 1; i < n - 1; i++) {
      for (int j = 1; j < m - 1; j++) {
        if (grid[i][j] == 1) {
          dfs(n, m, i, j, grid, true, cnt);
        }
      }
    }
    return cnt;
  }

  void dfs(int n, int m, int curx, int cury, vector<vector<int>> &grid,
           bool hint, int &cnt) {
    grid[curx][cury] = 0;
    if (hint) {
      cnt++;
    }
    for (int i = 0; i < 4; i++) {
      int nx = curx + dx[i];
      int ny = cury + dy[i];
      if (bound(n, m, nx, ny) && grid[nx][ny] == 1) {
        dfs(n, m, nx, ny, grid, hint, cnt);
      }
    }
  }
};