#include <cstring>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;
int N, M;
int A[101][101];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
vector<pair<int, int>> ans;

bool bound(int x, int y) {
  if (x >= 0 && x < N && y >= 0 && y < M) {
    return true;
  }
  return false;
}
void dfs(int x, int y, vector<vector<bool>> &visit) {
  visit[x][y] = true;
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (bound(nx, ny) && A[nx][ny] >= A[x][y] && !visit[nx][ny]) {
      dfs(nx, ny, visit);
    }
  }
}

void print() {
  for (auto p : ans) {
    cout << p.first << " " << p.second << endl;
  }
}
int main() {
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> A[i][j];
    }
  }
  vector<vector<bool>> visit1(N, vector<bool>(M, false));
  vector<vector<bool>> visit2(N, vector<bool>(M, false));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (i == 0 || j == 0) {
        dfs(i, j, visit1);
      }
      if (i == N - 1 || j == M - 1) {
        dfs(i, j, visit2);
      }
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (visit1[i][j] && visit2[i][j]) {
        ans.emplace_back(i, j);
      }
    }
  }
  print();
}