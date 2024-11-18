
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <queue>

#include <string>
#include <vector>
using namespace std;
int num;
int n, m;
char A[1001][1001];
int Y[1001][1001];
const int inf = 0x3f3f3f3f;

struct Point {
  int x;
  int y;
};

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
std::queue<Point> jpoints;
std::queue<Point> fpoints;
bool bound(int x, int y) {
  if (x >= 0 && x < n && y >= 0 && y < m && A[x][y] != '#') {
    return true;
  }
  return false;
}
void printA() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << A[i][j];
    }
    cout << endl;
  }
}
int bfs(Point &js, std::vector<Point> &fss) {
  jpoints.push(js);
  for (const auto &fs : fss) {
    fpoints.push(fs);
  }
  Y[js.x][js.y] = 0;
  while (!fpoints.empty() || !jpoints.empty()) {
    int fsize = fpoints.size();
    for (int i = 0; i < fsize; i++) {
      Point cur_f = fpoints.front();
      fpoints.pop();
      for (int j = 0; j < 4; j++) {
        int nx = cur_f.x + dx[j];
        int ny = cur_f.y + dy[j];
        if (bound(nx, ny) && A[nx][ny] != 'F') {
          A[nx][ny] = 'F';
          fpoints.push({nx, ny});
        }
      }
    }
    int jsize = jpoints.size();
    for (int i = 0; i < jsize; i++) {
      Point cur_j = jpoints.front();
      jpoints.pop();
      // if (cur_j.x == n - 1 || cur_j.y == m - 1) {
      //   bool has_fire = false;
      //   for (int j = 0; j < 4; j++) {
      //     int prex = cur_j.x + dx[j];
      //     int prey = cur_j.y + dy[j];
      //     if (bound(prex, prey) && A[prex][prey] == 'F') {
      //       has_fire = true;
      //       break;
      //     }
      //   }
      //   if (!has_fire) {
      //     return Y[cur_j.x][cur_j.y];
      //   }
      // }

      if (cur_j.x == n - 1 || cur_j.y == m - 1 || cur_j.x == 0 ||
          cur_j.y == 0) {
        return Y[cur_j.x][cur_j.y];
      }
      for (int j = 0; j < 4; j++) {
        int nx = cur_j.x + dx[j];
        int ny = cur_j.y + dy[j];
        if (bound(nx, ny) && A[nx][ny] != 'F' &&
            Y[cur_j.x][cur_j.y] + 1 < Y[nx][ny]) {
          Y[nx][ny] = Y[cur_j.x][cur_j.y] + 1;
          jpoints.push({nx, ny});
        }
      }
    }
  }
  return inf;
}

int main() {
  std::vector<string> anss;
  cin >> num;
  while (num--) {
    cin >> n >> m;
    memset(Y, inf, sizeof(Y));
    while (!jpoints.empty()) {
      jpoints.pop();
    }
    while (!fpoints.empty()) {
      fpoints.pop();
    }
    Point JS;
    std::vector<Point> FSS;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> A[i][j];
        if (A[i][j] == 'J') {
          JS.x = i;
          JS.y = j;
        }
        if (A[i][j] == 'F') {
          Point p{i, j};
          FSS.emplace_back(p);
        }
      }
    }
    int ans = bfs(JS, FSS);

    if (ans == inf) {
      // anss.emplace_back("IMPOSSIBLE");
      cout << "IMPOSSIBLE" << endl;
    } else {
      // anss.emplace_back(to_string(ans + 1));
      cout << ans + 1 << endl;
    }
  }
  // for (const auto &an : anss) {
  //   cout << an << endl;
  // }
  return 0;
}