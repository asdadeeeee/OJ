#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <ostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;
int M, N;
int mat[16][16];
int ans[16][16];
int temp[16][16];
queue<int> bfs_que_;
set<int> mat_set_;
int res = 0;

int dx[5] = {-1, 0, 1, 0, 0};
int dy[5] = {0, 0, 0, 1, -1};
bool bound(int x, int y) {
  if (x >= 0 && x < M && y >= 0 && y < N) {
    return true;
  }
  return false;
}

// void reverse(int *mat, int x, int y) {
//   ans[x][y] ^= 1;
//   for (int i = 0; i < 5; i++) {
//     int nx = x + dx[i];
//     int ny = y + dy[i];
//     if (bound(nx, ny)) {
//       mat[nx * N + ny] ^= 1;
//     }
//   }
// }

void reverse(int x, int y) {
  ans[x][y] ^= 1;
  for (int i = 0; i < 5; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (bound(nx, ny)) {
      temp[nx][ny] ^= 1;
    }
  }
}

bool AllZero(int mat[][16]) {
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      if (mat[i][j] == 1) {
        return false;
      }
    }
  }
  return true;
}

void printmat(int mat[][16]) {
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      cout << mat[i][j] << " ";
    }
    cout << endl;
  }
}
int encode(int mat[][16]) {
  int x = 0;
  for (int i = 0; i < M; ++i) {
    for (int j = 0; j < N; ++j) {
      x = x * 2 + mat[i][j];
    }
  }
  return x;
}

void decode(int x) {
  memset(temp, 0, sizeof(temp));
  for (int i = M - 1; i >= 0; i--) {
    for (int j = N - 1; j >= 0; j--) {
      temp[i][j] = x & 1;
      x >>= 1;
    }
  }
}
void minFlips(int mat[][16]) {
  int mat_val = encode(mat);
  bfs_que_.push(mat_val);
  mat_set_.insert(mat_val);
  if (AllZero(mat)) {
    printmat(ans);
    return;
  }
  while (!bfs_que_.empty()) {
    res++;
    printf("res = %d\n", res);
    int length = bfs_que_.size();
    for (int k = 0; k < length; k++) {
      int cur_mat_value = bfs_que_.front();
      bfs_que_.pop();
      decode(cur_mat_value);
      for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
          // reverse(&temp, i, j);
          reverse(i, j);
          if (AllZero(temp)) {
            printmat(ans);
            return;
          }
          int temp_mat_value = encode(temp);
          if (mat_set_.find(temp_mat_value) == mat_set_.end()) {
            mat_set_.insert(temp_mat_value);
            bfs_que_.push(temp_mat_value);
          }
          // reverse(&temp, i, j);
          reverse(i, j);
        }
      }
    }
  }
  cout << "IMPOSSIBLE" << endl;
  return;
}
int main() {

  cin >> M >> N;

  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      cin >> mat[i][j];
    }
  }
  minFlips(mat);
  cout << res << endl;

  // printAns();

  return 0;
}
