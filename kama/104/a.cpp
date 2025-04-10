#include <cstring>
#include <iostream>
#include <memory>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;
int N, M;
int A[51][51];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int visit[51][51];
int labels[51][51];
int sizes[51];
bool bound(int x, int y) {
  if (x >= 0 && x < N && y >= 0 && y < M) {
    return true;
  }
  return false;
}
void dfs(int x, int y, int labal, int &size) {
  visit[x][y] = true;
  labels[x][y] = labal;
  size++;
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (bound(nx, ny) && A[nx][ny] == 1 && !visit[nx][ny]) {
      dfs(nx, ny, labal, size);
    }
  }
}
int main() {
  memset(visit, false, sizeof(visit));
  memset(sizes, 0, sizeof(sizes));
  memset(labels, -1, sizeof(labels));
  cin >> N >> M;
  bool all_land = true;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> A[i][j];
      if (A[i][j] == 0) {
        all_land = false;
      }
    }
  }
  if (all_land) {
    cout << N * M;
    return 0;
  }
  int label = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (A[i][j] == 1 && !visit[i][j]) {
        int size = 0;
        dfs(i, j, label, size);
        sizes[label] = size;
        label++;
      }
    }
  }
  int ans = 0;
  unordered_set<int> temp_visit;
  int temp = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (A[i][j] == 0) {
        temp_visit.clear();
        temp = 1;
        ans = max(ans, temp);
        for (int k = 0; k < 4; k++) {
          int nx = i + dx[k];
          int ny = j + dy[k];
          if (bound(nx, ny) && A[nx][ny] == 1 &&
              temp_visit.find(labels[nx][ny]) == temp_visit.end()) {
            temp_visit.insert(labels[nx][ny]);
            temp += sizes[labels[nx][ny]];
            ans = max(ans, temp);
          }
        }
      }
    }
  }
  cout << ans;
  return 0;
}
