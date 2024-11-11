#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <ostream>
#include <queue>
#include <vector>

using namespace std;

bool memo[101][101];
int A, B, C;
int ans = 0;

const int inf = 0x3f3f3f3f;
struct Point {
  int x;
  int y;
  int pre;
  int move;
};

std::vector<Point> points;
int bfs() {
  int cur = 0;
  Point start{0, 0, -1, -1};
  points.push_back(start);
  memo[0][0] = true;
  while (cur < points.size()) {
    Point p = points.at(cur);
    if (p.x == C || p.y == C) {
      return cur;
    }

    for (int i = 0; i < 6; i++) {
      switch (i) {
      case 0: {
        if (p.x == A || memo[A][p.y]) {
          break;
        }
        Point newp{A, p.y, cur, 0};
        points.push_back(newp);
        memo[A][p.y] = true;
        break;
      }
      case 1: {
        if (p.y == B || memo[p.x][B]) {
          break;
        }
        Point newp{p.x, B, cur, 1};
        points.push_back(newp);
        memo[p.x][B] = true;
        break;
      }
      case 2: {
        if (p.x == 0 || memo[0][p.y]) {
          break;
        }
        Point newp{0, p.y, cur, 2};
        points.push_back(newp);
        memo[0][p.y] = true;
        break;
      }
      case 3: {
        if (p.y == 0 || memo[p.x][0]) {
          break;
        }
        Point newp{p.x, 0, cur, 3};
        points.push_back(newp);
        memo[p.x][0] = true;
        break;
      }
      case 4: {
        int mount = min(p.x, B - p.y);
        if (mount == 0 || memo[p.x - mount][p.y + mount]) {
          break;
        }
        Point newp{p.x - mount, p.y + mount, cur, 4};
        points.push_back(newp);
        memo[p.x - mount][p.y + mount] = true;
        break;
      }
      case 5: {
        int mount = min(A - p.x, p.y);
        if (mount == 0 || memo[p.x + mount][p.y - mount]) {
          break;
        }
        Point newp{p.x + mount, p.y - mount, cur, 5};
        points.push_back(newp);
        memo[p.x + mount][p.y - mount] = true;
        break;
      }
      }
    }
    cur++;
  }
  return -2;
}

string moves[6] = {"FILL(1)", "FILL(2)",   "DROP(1)",
                   "DROP(2)", "POUR(1,2)", "POUR(2,1)"};
int length = 0;
void printans(int idx) {
  if (idx == -2) {
    cout << "impossible" << endl;
    return;
  }

  if (idx == 0) {
    cout << length << endl;
  } else {
    length++;
    int pre = points[idx].pre;
    printans(pre);
    cout << moves[points[idx].move] << endl;
  }
}
int main() {
  memset(memo, false, sizeof(memo));
  points.clear();
  cin >> A >> B >> C;
  int ans = bfs();
  printans(ans);

  // printAns();

  return 0;
}
