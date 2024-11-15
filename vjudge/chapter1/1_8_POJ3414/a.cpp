#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <ostream>
#include <queue>
#include <vector>

using namespace std;

int memo[102][102];
int S, N, M;
int ans = 0;

const int inf = 0x3f3f3f3f;
struct Point {
  int x;
  int y;
  // int pre;
  // int move;
};

std::queue<Point> points;
void bfs() {
  memset(memo, inf, sizeof(memo));
  Point start{0, 0};
  points.push(start);
  memo[0][0] = 0;
  while (!points.empty()) {
    Point p = points.front();
    points.pop();
    if (((p.x + p.y == S) && (p.x == p.y)) || (p.x == S / 2 && p.y == 0) ||
        (p.y == S / 2 && p.x == 0)) {
      return;
    }

    for (int i = 0; i < 6; i++) {
      switch (i) {
      case 0: {
        int mount = min(S - (p.x + p.y), N - p.x);
        if (p.x == N || p.x + p.y == S ||
            memo[p.x][p.y] + 1 >= memo[p.x + mount][p.y]) {
          continue;
        }
        Point newp{p.x + mount, p.y};
        points.push(newp);
        memo[p.x + mount][p.y] = memo[p.x][p.y] + 1;
        break;
      }
      case 1: {
        int mount = min(S - (p.x + p.y), M - p.y);
        if (p.y == M || p.x + p.y == S ||
            memo[p.x][p.y] + 1 >= memo[p.x][p.y + mount]) {
          continue;
        }
        Point newp{p.x, p.y + mount};
        points.push(newp);
        memo[p.x][p.y + mount] = memo[p.x][p.y] + 1;
        break;
      }
      case 2: {
        if (p.x == 0 || memo[p.x][p.y] + 1 >= memo[0][p.y]) {
          continue;
        }
        Point newp{0, p.y};
        points.push(newp);
        memo[0][p.y] = memo[p.x][p.y] + 1;
        break;
      }
      case 3: {
        if (p.y == 0 || memo[p.x][p.y] + 1 >= memo[p.x][0]) {
          continue;
        }
        Point newp{p.x, 0};
        points.push(newp);
        memo[p.x][0] = memo[p.x][p.y] + 1;
        break;
      }
      case 4: {
        int mount = min(p.x, M - p.y);
        if (mount == 0 ||
            memo[p.x][p.y] + 1 >= memo[p.x - mount][p.y + mount]) {
          continue;
        }
        Point newp{p.x - mount, p.y + mount};
        points.push(newp);
        memo[p.x - mount][p.y + mount] = memo[p.x][p.y] + 1;
        break;
      }
      case 5: {
        int mount = min(N - p.x, p.y);
        if (mount == 0 ||
            memo[p.x][p.y] + 1 >= memo[p.x + mount][p.y - mount]) {
          continue;
        }
        Point newp{p.x + mount, p.y - mount};
        points.push(newp);
        memo[p.x + mount][p.y - mount] = memo[p.x][p.y] + 1;
        break;
      }
      }
    }
  }
}

string moves[6] = {"FILL(1)", "FILL(2)",   "DROP(1)",
                   "DROP(2)", "POUR(1,2)", "POUR(2,1)"};

int main() {
  while (true) {
    memset(memo, inf, sizeof(memo));
    cin >> S >> N >> M;
    if (S == 0 || N == 0 || M == 0) {
      break;
    }
    while (!points.empty()) {
      points.pop();
    }
    if (S % 2 == 1) {
      cout << "NO" << endl;
      continue;
    }

    bfs();
    if (memo[S / 2][S / 2] != inf) {
      cout << memo[S / 2][S / 2] << endl;
    } else if (memo[S / 2][0] != inf) {
      cout << memo[S / 2][0] << endl;
    } else if (memo[0][S / 2] != inf) {
      cout << memo[0][S / 2] << endl;
    } else {
      cout << "NO" << endl;
    }
  }

  // printAns();

  return 0;
}
