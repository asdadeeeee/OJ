#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <ostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;
const int inf = 0x3f3f3f3f;
int M, N;
int mat[16][16];
int ans[16][16];
int save[16][16];
int temp[16][16];
queue<int> bfs_que_;
set<int> mat_set_;
int res = inf;
bool flag = false;
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

void reverse(int x, int y, int hint) {
  if (!hint) {
    return;
  }
  save[x][y] ^= 1;
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

void setZero(int arr[][16]) //初始化翻转次数
{
  for (int i = 0; i < M; i++)
    for (int j = 0; j < N; j++)
      arr[i][j] = 0;
}

void printmat(int mat[][16]) {
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      cout << mat[i][j] << " ";
    }
    cout << endl;
  }
}
int getSum(int mat[][16]) {
  int sum = 0;
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      sum += mat[i][j];
    }
  }
  return sum;
}

void copyArr(int des[][16], int res[][16]) {
  for (int i = 0; i < M; i++)
    for (int j = 0; j < N; j++)
      des[i][j] = res[i][j];
}
void dfs(int k) {
  if (k == M) {
    for (int i = 0; i < N; i++) {
      if (temp[k - 1][i]) {
        return;
      }
    }
    flag = true;
    int sum_ = getSum(save);
    if (sum_ < res) {
      res = sum_;
      copyArr(ans, save);
    }
    return;
  }
  for (int i = 0; i < N; i++) {
    reverse(k, i, temp[k - 1][i]);
  }
  dfs(k + 1);
}

void resolve() {

  setZero(ans);

  for (int k = 0; k < 1 << N; k++) {
    copyArr(temp, mat);
    setZero(save);
    for (int i = 0; i < N; i++) {
      int t = 0;
      if ((k & 0x1 << i) == 0) {
        t = 0;
      } else {
        t = 1;
      }
      reverse(0, i, t);
    }
    dfs(1);
  }
}
int main() {

  cin >> M >> N;

  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      cin >> mat[i][j];
    }
  }
  resolve();
  // cout << res << endl;
  if (flag) {
    printmat(ans);
  } else {
    cout << "IMPOSSIBLE" << endl;
  }

  return 0;
}
