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
  int numIslands(vector<vector<char>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == '1') {
          cnt++;
          dfs(n, m, i, j, grid);
        }
      }
    }
    return cnt;
  }
  void dfs(int n, int m, int curx, int cury, vector<vector<char>> &grid) {
    grid[curx][cury] = '0';
    for (int i = 0; i < 4; i++) {
      int nx = curx + dx[i];
      int ny = cury + dy[i];
      if (bound(n, m, nx, ny) && grid[nx][ny] == '1') {
        dfs(n, m, nx, ny, grid);
      }
    }
  }
};
