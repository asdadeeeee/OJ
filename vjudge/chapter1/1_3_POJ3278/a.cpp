#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <ostream>
#include <queue>
#include <vector>

using namespace std;

int s, e;
int sig[100001];
const int inf = 0x3f3f3f3f;
std::queue<int> points;

bool valid(int x) {
  if (x >= 0 && x <= 100000 && sig[x] == inf) {
    return true;
  }
  return false;
}

int bfs(int start) {
  sig[start] = 0;
  points.push(start);
  while (!points.empty()) {
    int p = points.front();
    points.pop();
    if (p == e) {
      break;
    }
    int nx;
    if (p < 0) {
      nx = p + 1;
      if (valid(nx)) {
        points.push(nx);
        sig[nx] = sig[p] + 1;
      }

    } else if (p > 100000) {
      nx = p - 1;
      if (valid(nx)) {
        points.push(nx);
        sig[nx] = sig[p] + 1;
      }
    } else {
      for (int i = 0; i < 3; i++) {

        switch (i) {
        case 0: {
          nx = p + 1;
          break;
        }
        case 1: {
          nx = p - 1;
          break;
        }
        case 2: {
          nx = p * 2;
          break;
        }
        }
        if (valid(nx)) {
          points.push(nx);
          sig[nx] = sig[p] + 1;
        }
      }
    }
  }
  return sig[e];
}

int main() {
  memset(sig, inf, sizeof(sig));
  while (!points.empty()) {
    points.pop();
  };
  cin >> s >> e;
  int ans = bfs(s);
  cout << sig[e] << endl;

  // printAns();

  return 0;
}
