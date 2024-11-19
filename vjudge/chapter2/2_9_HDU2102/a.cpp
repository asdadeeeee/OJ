#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int inf = 0x3f3f3f3f;
int C, N, M, T;
char A[11][11][11];
int step[11][11][11];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
bool bound(int z, int x, int y) {
  if (x >= 0 && x < N && y >= 0 && y < M && A[z][x][y] != '*') {
    return true;
  }
  return false;
}
struct Point {
  int z;
  int x;
  int y;
};
Point start_;
Point end_;
std::queue<Point> points;
void bfs(Point start) {
  step[start.z][start.x][start.y] = 0;
  points.push(start);
  while (!points.empty()) {
    Point cur = points.front();
    points.pop();
    if (cur.x == end_.x && cur.y == end_.y && cur.z == end_.z) {
      return;
    }
    for (int i = 0; i < 4; i++) {
      int nx = cur.x + dx[i];
      int ny = cur.y + dy[i];
      if (bound(cur.z, nx, ny)) {
        if (A[cur.z][nx][ny] != '#' &&
            step[cur.z][cur.x][cur.y] + 1 < step[cur.z][nx][ny]) {
          step[cur.z][nx][ny] = step[cur.z][cur.x][cur.y] + 1;
          points.push({cur.z, nx, ny});
        } else if (A[cur.z][nx][ny] == '#') {
          int nz = 1 - cur.z;
          if (bound(nz, nx, ny) && A[nz][nx][ny] != '#' &&
              step[cur.z][cur.x][cur.y] + 1 < step[nz][nx][ny]) {
            step[cur.z][nx][ny] = step[cur.z][cur.x][cur.y] + 1;
            step[nz][nx][ny] = step[cur.z][cur.x][cur.y] + 1;
            points.push({nz, nx, ny});
          }
        }
      }
    }
  }
}
int main() {
  cin >> C;
  while (C--) {
    memset(step, inf, sizeof(step));
    while (!points.empty()) {
      points.pop();
    }

    cin >> N >> M >> T;
    for (int k = 0; k < 2; k++) {
      for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
          cin >> A[k][i][j];
          //   if (A[k][i][j] == 'S') {
          //     start_.z = k;
          //     start_.x = i;
          //     start_.y = j;
          //   }
          if (A[k][i][j] == 'P') {
            end_.z = k;
            end_.x = i;
            end_.y = j;
          }
        }
      }
    }
    bfs(start_);
    if (step[end_.z][end_.x][end_.y] == inf ||
        step[end_.z][end_.x][end_.y] > T) {
      cout << "NO" << endl;
    } else if (step[end_.z][end_.x][end_.y] <= T) {
      cout << "YES" << endl;
      // cout << step[end_.z][end_.x][end_.y] << endl;
    }
  }
  return 0;
}