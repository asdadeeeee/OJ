#include <cstring>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;
int N, M;
int A[51][51];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
bool visit[51][51];

bool bound(int x, int y) {
  if (x >= 0 && x < N && y >= 0 && y < M) {
    return true;
  }
  return false;
}
int dfs(int x, int y) {
  visit[x][y] = true;
  int temp = 0;
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (bound(nx, ny)) {
      if (A[nx][ny] == 0) {
        temp++;
      } else {
        if (!visit[nx][ny]) {
          temp += dfs(nx, ny);
        }
      }
    } else {
      temp++;
    }
  }
  return temp;
}

int main() {
  memset(visit, false, sizeof(visit));
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> A[i][j];
    }
  }
  int ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (!visit[i][j] && A[i][j] == 1) {
        ans = dfs(i, j);
      }
    }
  }
  cout << ans;
  return 0;
}