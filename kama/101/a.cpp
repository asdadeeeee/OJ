#include <cstring>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;
int N, M;
int A[51][51];
bool visit[51][51];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int ans = 0;
int temp = 0;
bool bound(int x, int y) {
  if (x >= 0 && x < N && y >= 0 && y < M && A[x][y] == 1) {
    return true;
  }
  return false;
}

void dfs(int x, int y) {
  if (visit[x][y]) {
    return;
  }
  visit[x][y] = true;
  temp++;
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (bound(nx, ny)) {
      dfs(nx, ny);
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
      if (i == 0 || i == N - 1 || j == 0 || j == M - 1) {
        if (!visit[i][j] && A[i][j] == 1) {
          dfs(i, j);
        }
      }
    }
  }
  for (int i = 1; i < N - 1; i++) {
    for (int j = 1; j < M - 1; j++) {
      if (!visit[i][j] && A[i][j] == 1) {
        temp = 0;
        dfs(i, j);
        ans += temp;
      }
    }
  }
  cout << ans << endl;
}