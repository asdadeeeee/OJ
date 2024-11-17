
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <queue>

#include <vector>
using namespace std;
int n, m;
char A[201][201];
int Y[201][201];
int M[201][201];
const int inf = 0x3f3f3f3f;

struct Point {
  int x;
  int y;
};

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
std::queue<Point> points;
bool bound(int x, int y) {
  if (x >= 0 && x < n && y >= 0 && y < m && A[x][y] != '#') {
    return true;
  }
  return false;
}
void bfs(int hint, Point begin) {
  points.push(begin);
  if (hint) {
    Y[begin.x][begin.y] = 0;
  } else {
    M[begin.x][begin.y] = 0;
  }
  while (!points.empty()) {
    Point p = points.front();
    points.pop();
    for (int i = 0; i < 4; i++) {
      int nx = p.x + dx[i];
      int ny = p.y + dy[i];
      if (bound(nx, ny)) {
        if (hint) {
          if (Y[p.x][p.y] + 1 < Y[nx][ny]) {
            Y[nx][ny] = Y[p.x][p.y] + 1;
            points.push({nx, ny});
          }
        } else {
          if (M[p.x][p.y] + 1 < M[nx][ny]) {
            M[nx][ny] = M[p.x][p.y] + 1;
            points.push({nx, ny});
          }
        }
      }
    }
  }
}

int main() {
  while (cin >> n >> m) {
    memset(Y, inf, sizeof(Y));
    memset(M, inf, sizeof(M));
    while (!points.empty()) {
      points.pop();
    }
    Point YS;
    Point MS;
    vector<Point> kfcs;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> A[i][j];
        if (A[i][j] == 'Y') {
          YS.x = i;
          YS.y = j;
        }
        if (A[i][j] == 'M') {
          MS.x = i;
          MS.y = j;
        }
        if (A[i][j] == '@') {
          Point p{i, j};
          kfcs.insert(kfcs.end(), p);
        }
      }
    }
    bfs(1, YS);
    bfs(0, MS);
    int mindis = inf;
    for (int i = 0; i < kfcs.size(); i++) {
      const auto &kfc = kfcs.at(i);
      if (Y[kfc.x][kfc.y] == inf || M[kfc.x][kfc.y] == inf) {
        continue;
      }
      if (Y[kfc.x][kfc.y] + M[kfc.x][kfc.y] < mindis) {
        mindis = Y[kfc.x][kfc.y] + M[kfc.x][kfc.y];
      }
    }
    cout << mindis * 11 << endl;
  }
}