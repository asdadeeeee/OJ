
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <queue>

#include <string>
#include <vector>
using namespace std;
int num;
int n, m;
char A[11][11];
int Y[11][11];
const int inf = 0x3f3f3f3f;

struct Point {
  int x;
  int y;
};

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
std::queue<Point> points1;
std::queue<Point> points2;
bool bound(int x, int y) {
  if (x >= 0 && x < n && y >= 0 && y < m) {
    return true;
  }
  return false;
}

// void printA() {
//   for (int i = 0; i < n; i++) {
//     for (int j = 0; j < m; j++) {
//       cout << A[i][j];
//     }
//     cout << endl;
//   }
// }
int bfs(Point &fs1, Point &fs2) {
  int res = 0;

  points1.push(fs1);
  points2.push(fs2);
  Y[fs1.x][fs1.y] = 0;
  Y[fs2.x][fs2.y] = 0;

  while (!points1.empty() || !points2.empty()) {
    int size1 = points1.size();
    for (int i = 0; i < size1; i++) {
      Point cur_f = points1.front();
      points1.pop();
      for (int j = 0; j < 4; j++) {
        int nx = cur_f.x + dx[j];
        int ny = cur_f.y + dy[j];
        if (bound(nx, ny) && Y[nx][ny] == inf && A[nx][ny] == '#') {
          Y[nx][ny] = Y[cur_f.x][cur_f.y] + 1;
          points1.push({nx, ny});
        }
      }
    }
    int size2 = points2.size();
    for (int i = 0; i < size2; i++) {
      Point cur_f = points2.front();
      points2.pop();
      for (int j = 0; j < 4; j++) {
        int nx = cur_f.x + dx[j];
        int ny = cur_f.y + dy[j];
        if (bound(nx, ny) && Y[nx][ny] == inf && A[nx][ny] == '#') {
          Y[nx][ny] = Y[cur_f.x][cur_f.y] + 1;
          points2.push({nx, ny});
        }
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (A[i][j] == '#') {
        if (Y[i][j] == inf) {
          res = -1;
          return res;
        } else if (Y[i][j] > res) {
          res = Y[i][j];
        }
      }
    }
  }
  return res;
}

int dfs() {
  int ans = inf;
  for (int iA = 0; iA < n; iA++) {
    for (int jA = 0; jA < m; jA++) {
      if (A[iA][jA] == '#') {
        Point fs1{iA, jA};
        for (int iB = 0; iB < n; iB++) {
          for (int jB = 0; jB < m; jB++) {
            if (A[iB][jB] == '#') {
              Point fs2{iB, jB};
              memset(Y, inf, sizeof(Y));
              int d = bfs(fs1, fs2);
              if (d >= 0 && d < ans) {
                ans = d;
              }
            }
          }
        }
      }
    }
  }
  return ans;
}
int main() {
  std::vector<string> anss;
  cin >> num;
  int case_id = 0;
  while (num--) {
    cin >> n >> m;
    memset(Y, inf, sizeof(Y));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> A[i][j];
      }
    }
    int ans = dfs();
    if (ans == inf) {
      ans = -1;
    }
    cout << "Case " << ++case_id << ": " << ans;
  }
  // for (const auto &an : anss) {
  //   cout << an << endl;
  // }
  return 0;
}