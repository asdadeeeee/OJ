#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <ostream>
#include <queue>
#include <vector>

#include <cmath>
using namespace std;

int memo[11][11][11][11];
int n;

const int inf = 0x3f3f3f3f;
struct Point {
  int q;
  int w;
  int e;
  int r;
  // int pre;
  // int move;
  bool operator==(const Point &other) const {
    return (q == other.q) && (w == other.w) && (e == other.e) && (r == other.r);
  }
};

bool if_prime(int t) {
  for (int i = 2; i <= sqrt(t); i++) {
    if (t % i == 0) {
      return false;
    }
  }
  return true;
}

Point decode(int t) {
  int q = t / 1000;
  int w = (t / 100) % 10;
  int e = (t / 10) % 10;
  int r = t % 10;
  return Point{q, w, e, r};
}
int encodeF(int q, int w, int e, int r) {
  return q * 1000 + w * 100 + e * 10 + r;
}
int encodeP(Point p) { return encodeF(p.q, p.w, p.e, p.r); }

std::queue<Point> points;
void bfs(Point start, Point end) {
  memset(memo, inf, sizeof(memo));
  points.push(start);
  memo[start.q][start.w][start.e][start.r] = 0;
  while (!points.empty()) {
    Point p = points.front();
    points.pop();
    if (p == end) {
      return;
    }
    for (int i = 0; i < 4; i++) {
      switch (i) {
      case 0: {
        for (int j = 1; j <= 9; j++) {
          if (j == p.q || !if_prime(encodeF(j, p.w, p.e, p.r)) ||
              memo[p.q][p.w][p.e][p.r] + 1 >= memo[j][p.w][p.e][p.r]) {
            continue;
          }
          memo[j][p.w][p.e][p.r] = memo[p.q][p.w][p.e][p.r] + 1;
          points.push(Point{j, p.w, p.e, p.r});
        }
        break;
      }
      case 1: {
        for (int j = 0; j <= 9; j++) {
          if (j == p.w || !if_prime(encodeF(p.q, j, p.e, p.r)) ||
              memo[p.q][p.w][p.e][p.r] + 1 >= memo[p.q][j][p.e][p.r]) {
            continue;
          }
          memo[p.q][j][p.e][p.r] = memo[p.q][p.w][p.e][p.r] + 1;
          points.push(Point{p.q, j, p.e, p.r});
        }
        break;
      }
      case 2: {
        for (int j = 0; j <= 9; j++) {
          if (j == p.e || !if_prime(encodeF(p.q, p.w, j, p.r)) ||
              memo[p.q][p.w][p.e][p.r] + 1 >= memo[p.q][p.w][j][p.r]) {
            continue;
          }
          memo[p.q][p.w][j][p.r] = memo[p.q][p.w][p.e][p.r] + 1;
          points.push(Point{p.q, p.w, j, p.r});
        }
        break;
      }
      case 3: {
        for (int j = 0; j <= 9; j++) {
          if (j == p.r || !if_prime(encodeF(p.q, p.w, p.e, j)) ||
              memo[p.q][p.w][p.e][p.r] + 1 >= memo[p.q][p.w][p.e][j]) {
            continue;
          }
          memo[p.q][p.w][p.e][j] = memo[p.q][p.w][p.e][p.r] + 1;
          points.push(Point{p.q, p.w, p.e, j});
        }
        break;
      }
      }
    }
  }
}

int main() {

  memset(memo, inf, sizeof(memo));
  cin >> n;
  int start, end;
  while (n--) {
    cin >> start >> end;
    Point s = decode(start);
    Point e = decode(end);
    while (!points.empty()) {
      points.pop();
    }
    bfs(s, e);
    if (memo[e.q][e.w][e.e][e.r] != inf) {
      cout << memo[e.q][e.w][e.e][e.r] << endl;
    } else {
      cout << "Impossible" << endl;
    }
  }

  // printAns();

  return 0;
}
