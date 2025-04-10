#include <algorithm>
#include <cstring>
#include <iostream>
#include <memory>
#include <stack>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
  inline bool atbound1(int x, int y) {
    if (x == 0 || y == 0) {
      return true;
    }
    return false;
  }
  inline bool atbound2(int x, int y) {
    if (x == N - 1 || y == M - 1) {
      return true;
    }
    return false;
  }

  inline bool bound(int x, int y) {
    if (x >= 0 && x < N && y >= 0 && y < M) {
      return true;
    }
    return false;
  }
  void dfs(const vector<vector<int>> &heights, int x, int y,
           vector<vector<bool>> &visit) {
    visit[x][y] = true;
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (bound(nx, ny) && heights[nx][ny] >= heights[x][y] && !visit[nx][ny]) {
        dfs(heights, nx, ny, visit);
      }
    }
  }

  vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
    N = heights.size();
    M = heights[0].size();
    vector<vector<bool>> visit1(N, vector<bool>(M, false));
    vector<vector<bool>> visit2(N, vector<bool>(M, false));
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        if (i == 0 || j == 0) {
          dfs(heights, i, j, visit1);
        }
        if (i == N - 1 || j == M - 1) {
          dfs(heights, i, j, visit2);
        }
      }
    }
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        if (visit1[i][j] && visit2[i][j]) {
          ans.push_back({i, j});
        }
      }
    }
    return ans;
  }
  int N, M;
  int dx[4] = {0, 0, 1, -1};
  int dy[4] = {1, -1, 0, 0};
  int visit[201][201];
  bool feet[201][201];
  vector<vector<int>> ans;
};
