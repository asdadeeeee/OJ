#include <cstring>
#include <iostream>
#include <memory>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  int N, M;
  int dx[4] = {0, 0, 1, -1};
  int dy[4] = {1, -1, 0, 0};
  bool visit[101][101];

  bool bound(int x, int y) {
    if (x >= 0 && x < N && y >= 0 && y < M) {
      return true;
    }
    return false;
  }
  int dfs(vector<vector<int>> &grid, int x, int y) {
    visit[x][y] = true;
    int temp = 0;
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (bound(nx, ny)) {
        if (grid[nx][ny] == 0) {
          temp++;
        } else {
          if (!visit[nx][ny]) {
            temp += dfs(grid, nx, ny);
          }
        }
      } else {
        temp++;
      }
    }
    return temp;
  }
  int islandPerimeter(vector<vector<int>> &grid) {
    N = grid.size();
    M = grid[0].size();
    memset(visit, false, sizeof(visit));
    int ans = 0;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        if (!visit[i][j] && grid[i][j] == 1) {
          ans = dfs(grid, i, j);
        }
      }
    }
    return ans;
  }
};