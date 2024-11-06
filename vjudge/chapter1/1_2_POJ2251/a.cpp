#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <ostream>
#include <queue>
#include <vector>

using namespace std;

char A[31][31][31];
int L, R, C;
int ans = 0;
int ex, ey, ez;
int sx, sy, sz;
int sig[31][31][31];
const int inf = 0x3f3f3f3f;
struct Point {
  int z;
  int x;
  int y;
};

std::queue<Point> points;

int dz[6] = {1, -1, 0, 0, 0, 0};
int dx[6] = {0, 0, -1, 0, 1, 0};
int dy[6] = {0, 0, 0, 1, 0, -1};
void printA() {
  for (int i = 0; i < L; i++) {
    for (int j = 0; j < R; j++) {
      for (int k = 0; k < C; k++) {
        cout << A[i][j][k];
      }
      cout << endl;
    }
    cout << endl;
  }
}
bool valid(Point p) {
  if (p.x >= 0 && p.x < R && p.y >= 0 && p.y < C && p.z >= 0 && p.z < L &&
      A[p.z][p.x][p.y] != '#') {
    return true;
  }
  return false;
}

int bfs(Point p) {
  sig[p.z][p.x][p.y] = 0;
  points.push(p);
  while (!points.empty()) {
    Point p = points.front();
    points.pop();
    if (p.x == ex && p.y == ey && p.z == ez) {
      break;
    }

    for (int i = 0; i < 6; i++) {
      int nx = p.x + dx[i];
      int ny = p.y + dy[i];
      int nz = p.z + dz[i];
      Point np{nz, nx, ny};
      if (sig[nz][nx][ny] == inf && valid(np)) {
        points.push(np);
        sig[nz][nx][ny] = sig[p.z][p.x][p.y] + 1;
      }
    }
  }
  return sig[ez][ex][ey];
}

int main() {

  while (true) {
    memset(sig, inf, sizeof(sig));
    while (!points.empty()) {
      points.pop();
    };
    cin >> L >> R >> C;
    if (L == 0 || R == 0 || R == 0) {
      break;
    }
    for (int i = 0; i < L; i++) {
      for (int j = 0; j < R; j++) {
        for (int k = 0; k < C; k++) {
          cin >> A[i][j][k];
          if (A[i][j][k] == 'S') {
            sx = j;
            sy = k;
            sz = i;
          } else if (A[i][j][k] == 'E') {
            ex = j;
            ey = k;
            ez = i;
          }
        }
      }
    }
    Point sp{sz, sx, sy};
    int ans = bfs(sp);
    if (ans != inf) {
      cout << "Escaped in " << sig[ez][ex][ey] << " minute(s)." << endl;
    } else {
      cout << "Trapped!" << endl;
    }
  }
  // printAns();

  return 0;
}
