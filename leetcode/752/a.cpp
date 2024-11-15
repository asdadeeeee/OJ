#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <ostream>
#include <queue>
#include <string>
#include <vector>

#include <cmath>
using namespace std;
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
class Solution {
public:
  int openLock(vector<string> &deadends, string target) {
    Point start{0, 0, 0, 0};
    Point e = decode(target);
    bfs(start, e, deadends);
    if (memo[e.q][e.w][e.e][e.r] != inf) {
      return memo[e.q][e.w][e.e][e.r];
    } else {
      return -1;
    }
  }

  int nextnum(int old_num, int k) {
    switch (k) {
    case 0: {
      if (old_num == 9) {
        return 0;
      } else {
        return old_num + 1;
      }
      break;
    }
    case 1: {
      if (old_num == 0) {
        return 9;
      } else {
        return old_num - 1;
      }
      break;
    }
    }
    return -1;
  }
  void bfs(Point start, Point end, vector<string> &deadends) {
    memset(memo, inf, sizeof(memo));
    points.push(start);
    memo[start.q][start.w][start.e][start.r] = 0;
    initdead(deadends);

    while (!points.empty()) {
      Point p = points.front();

      points.pop();
      if (p == end || memo[p.q][p.w][p.e][p.r] == -1) {
        return;
      }
      for (int i = 0; i < 4; i++) {
        switch (i) {
        case 0: {
          for (int k = 0; k < 2; k++) {
            int j = nextnum(p.q, k);
            if (memo[p.q][p.w][p.e][p.r] + 1 >= memo[j][p.w][p.e][p.r]) {
              continue;
            }
            memo[j][p.w][p.e][p.r] = memo[p.q][p.w][p.e][p.r] + 1;
            points.push(Point{j, p.w, p.e, p.r});
          }
          break;
        }
        case 1: {
          for (int k = 0; k < 2; k++) {
            int j = nextnum(p.w, k);

            if (memo[p.q][p.w][p.e][p.r] + 1 >= memo[p.q][j][p.e][p.r]) {
              continue;
            }
            memo[p.q][j][p.e][p.r] = memo[p.q][p.w][p.e][p.r] + 1;
            points.push(Point{p.q, j, p.e, p.r});
          }
          break;
        }
        case 2: {
          for (int k = 0; k < 2; k++) {
            int j = nextnum(p.e, k);

            if (memo[p.q][p.w][p.e][p.r] + 1 >= memo[p.q][p.w][j][p.r]) {
              continue;
            }
            memo[p.q][p.w][j][p.r] = memo[p.q][p.w][p.e][p.r] + 1;
            points.push(Point{p.q, p.w, j, p.r});
          }
          break;
        }
        case 3: {
          for (int k = 0; k < 2; k++) {
            int j = nextnum(p.r, k);

            if (memo[p.q][p.w][p.e][p.r] + 1 >= memo[p.q][p.w][p.e][j]) {
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

  int memo[11][11][11][11];
  const int inf = 0x3f3f3f3f;
  std::queue<Point> points;

  Point decode(string s) {
    int q = s[0] - '0';
    int w = s[1] - '0';
    int e = s[2] - '0';
    int r = s[3] - '0';
    return Point{q, w, e, r};
  }
  string encodeF(int q, int w, int e, int r) {
    return to_string(q) + to_string(w) + to_string(e) + to_string(r);
  }
  string encodeP(Point p) { return encodeF(p.q, p.w, p.e, p.r); }

  void initdead(vector<string> &deadends) {
    for (const auto &d : deadends) {
      Point p = decode(d);
      memo[p.q][p.w][p.e][p.r] = -1;
    }
  }
};

int main() {
  vector<string> deadends;
  Solution sol;
  // cout << *std::find(deadends.begin(), deadends.end(), sol.encodeF(8, 8, 8,
  // 8));

  int ans = sol.openLock(deadends, "8888");
  cout << ans;
}