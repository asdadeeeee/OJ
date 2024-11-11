#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <ostream>
#include <queue>
#include <set>
#include <vector>

#include <unordered_map>
using namespace std;

char A[101][101];
bool take[101][101];
int dx[8] = {-1, 1, 0, 0, 1, -1, 1, -1};
int dy[8] = {0, 0, 1, -1, 1, -1, -1, 1};

struct point {
  int x;
  int y;
};
std::queue<point> points;
int m, n;
int ans = 0;
bool bound(point s) {
  if (s.x >= 0 && s.x < m && s.y >= 0 && s.y < n && !take[s.x][s.y]) {
    return true;
  }
  return false;
}
bool if_oil(point s) {
  if (A[s.x][s.y] == '@') {
    return true;
  }
  return false;
}

void bfs(point s) {
  points.push(s);
  take[s.x][s.y] = true;
  while (!points.empty()) {
    point cur_p = points.front();
    points.pop();
    for (int i = 0; i < 8; i++) {
      int nx = cur_p.x + dx[i];
      int ny = cur_p.y + dy[i];
      point ns{nx, ny};
      if (bound(ns) && if_oil(ns)) {
        take[nx][ny] = true;
        points.push(ns);
      }
    }
  }
}

void find_all_oil() {
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      point cur_p{i, j};
      if (if_oil(cur_p) && bound(cur_p)) {
        ans++;
        while (!points.empty()) {
          points.pop();
        }
        bfs(cur_p);
      }
    }
  }
}
int main() {

  while (true) {
    while (!points.empty()) {
      points.pop();
    }
    memset(take, false, sizeof(take));
    ans = 0;
    cin >> m >> n;
    if (m == 0 || n == 0) {
      break;
    }
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        cin >> A[i][j];
      }
    }
    find_all_oil();
    cout << ans << endl;
    // printA(n);
  }
  // printAns();

  return 0;
}
