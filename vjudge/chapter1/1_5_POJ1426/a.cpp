
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <queue>

#include <string>
#include <vector>
using namespace std;
typedef long long LL;
int n;

std::queue<LL> points;

void bfs(LL start) {

  points.push(start);

  while (!points.empty()) {

    LL cur = points.front();
    points.pop();
    if (cur % n == 0) {
      cout << cur << endl;
      return;
    }
    for (int j = 0; j < 2; j++) {
      LL next = 0;
      switch (j) {
      case 0: {
        next = cur * 10;
        break;
      }
      case 1: {
        next = cur * 10 + 1;
        break;
      }
      }
      points.push(next);
    }
  }
}

int main() {
  while (true) {
    cin >> n;
    while (!points.empty()) {
      points.pop();
    }
    if (n == 0) {
      break;
    }
    bfs(1);
  }
  // for (const auto &an : anss) {
  //   cout << an << endl;
  // }
  return 0;
}