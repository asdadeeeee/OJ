#include <cstring>
#include <iostream>
#include <memory>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  inline bool bound(int x, int y) {
    if (x >= 0 && x < N && y >= 0 && y < N) {
      return true;
    }
    return false;
  }
  inline void dfs(const vector<vector<int>> &grid, int x, int y, int labal,
                  int &size) {
    visit[x][y] = true;
    labels[x][y] = labal;
    size++;
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (bound(nx, ny) && grid[nx][ny] == 1 && !visit[nx][ny]) {
        dfs(grid, nx, ny, labal, size);
      }
    }
  }
  int largestIsland(vector<vector<int>> &grid) {
    memset(visit, false, sizeof(visit));
    memset(sizes, 0, sizeof(sizes));
    memset(labels, -1, sizeof(labels));
    N = grid.size();
    bool all_land = true;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (grid[i][j] == 0) {
          all_land = false;
        }
      }
    }
    if (all_land) {
      return N * N;
    }
    int label = 0;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (grid[i][j] == 1 && !visit[i][j]) {
          int size = 0;
          dfs(grid, i, j, label, size);
          sizes[label] = size;
          label++;
        }
      }
    }
    int ans = 0;
    unordered_set<int> temp_visit;
    int temp = 0;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (grid[i][j] == 0) {
          temp_visit.clear();
          temp = 1;
          ans = max(ans, temp);
          for (int k = 0; k < 4; k++) {
            int nx = i + dx[k];
            int ny = j + dy[k];
            if (bound(nx, ny) && grid[nx][ny] == 1 &&
                temp_visit.find(labels[nx][ny]) == temp_visit.end()) {
              temp_visit.insert(labels[nx][ny]);
              temp += sizes[labels[nx][ny]];
              ans = max(ans, temp);
            }
          }
        }
      }
    }
    return ans;
  }

  int N;
  int dx[4] = {0, 0, 1, -1};
  int dy[4] = {1, -1, 0, 0};
  int visit[501][501];
  int labels[501][501];
  int sizes[260001];
};