#include <algorithm>
#include <cstring>
#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;
class Solution {
  int dx[5] = {0, 0, 0, 1, -1};
  int dy[5] = {0, 1, -1, 0, 0};

public:
  inline bool bound(int n, int m, int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
  }
  int numDistinctIslands(vector<vector<int>> &grid) {
    set<vector<int>> s;
    int n = grid.size();
    int m = grid[0].size();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        vector<int> temp;
        if (grid[i][j] == 1) {
          dfs(n, m, i, j, grid, temp);
          s.emplace(move(temp));
        }
      }
    }
    return s.size();
  }

  void dfs(int n, int m, int curx, int cury, vector<vector<int>> &grid,
           vector<int> &temp) {
    grid[curx][cury] = 0;
    for (int i = 1; i <= 4; i++) {
      int nx = curx + dx[i];
      int ny = cury + dy[i];
      if (bound(n, m, nx, ny) && grid[nx][ny] == 1) {
        temp.push_back(i);
        dfs(n, m, nx, ny, grid, temp);
        temp.push_back(0 - i);
      }
    }
  }
};

int main() {
  vector<vector<int>> nums = {
      {1, 1, 0, 1, 1}, {1, 0, 0, 0, 0}, {0, 0, 0, 0, 1}, {1, 1, 0, 1, 1}};

  Solution so;
  cout << so.numDistinctIslands(nums);
}