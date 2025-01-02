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

  int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2) {
    int n = grid1.size();
    int m = grid1[0].size();
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid2[i][j] == 1) {
          bool temp = true;
          dfs(n, m, i, j, grid1, grid2, temp);
          if (temp) {
            cnt++;
          }
        }
      }
    }
    return cnt;
  }

  void dfs(int n, int m, int curx, int cury, vector<vector<int>> &grid1,
           vector<vector<int>> &grid2, bool &temp) {
    grid2[curx][cury] = 0;
    if (grid1[curx][cury] == 0) {
      temp = false;
    }
    for (int i = 0; i < 4; i++) {
      int nx = curx + dx[i];
      int ny = cury + dy[i];
      if (bound(n, m, nx, ny) && grid2[nx][ny] == 1) {
        dfs(n, m, nx, ny, grid1, grid2, temp);
      }
    }
  }
};