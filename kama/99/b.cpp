#include <cstring>
#include <iostream>
#include <memory>
#include <queue>
#include <string>
#include <utility>
#include <vector>
using namespace std;
int N, M;
int A[51][51];
bool visit[51][51];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int ans = 0;
queue<pair<int, int>> q;
bool bound(int x, int y) {
  if (x >= 0 && x < N && y >= 0 && y < M && A[x][y] == 1) {
    return true;
  }
  return false;
}
void bfs(int x, int y) {
  while (!q.empty()) {
    q.pop();
  }
  q.push({x, y});
  visit[x][y] = true;
  while (!q.empty()) {
    auto cur = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int nx = cur.first + dx[i];
      int ny = cur.second + dy[i];
      if (bound(nx, ny) && !visit[nx][ny]) {
        q.push({nx, ny});
        visit[nx][ny] = true;
      }
    }
  }
}
int main() {
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> A[i][j];
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (!visit[i][j] && A[i][j] == 1) {
        ans++;
        bfs(i, j);
      }
    }
  }
  cout << ans << endl;
}
