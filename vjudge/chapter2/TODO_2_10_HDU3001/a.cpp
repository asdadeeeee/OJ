#include <cstring>
#include <iostream>
#include <memory>
#include <queue>
#include <vector>
using namespace std;
const int inf = 0x3f3f3f3f;
int ans = inf;
int n, m;
struct road {
  int des = -1;
  int price = -1;
};

struct point {
  int id;
  road roads[11];
};

point points[11];

int steps[11];
std::queue<int> res;

bool if_all_step() {
  for (int i = 1; i <= n; i++) {
    if (steps[i] == inf) {
      return false;
    }
  }
  return true;
}

int getstep() {
  int temp = 0;
  for (int i = 1; i <= n; i++) {
    if (steps[i] > temp) {
      temp = steps[i];
    }
  }
  return temp;
}
void bfs(int start) {
  steps[start] = 0;
  res.emplace(start);
  int dests = 0;
  while (!res.empty()) {
    dests++;
    int size = res.size();
    for (int i = 0; i < size; i++) {
      int cur = res.front();
      res.pop();
      // if (if_all_step()) {
      //   if (temp < ans) {
      //     ans = temp;
      //   }
      // }
      for (int i = 1; i <= n; i++) {
        if (points[cur].roads[i].des >= 0 && points[cur].roads[i].price >= 0) {
          int next = points[cur].roads[i].des;
          if (steps[cur] + points[cur].roads[i].price < steps[next]) {
            steps[next] = steps[cur] + points[cur].roads[i].price;
            res.emplace(next);
          }
        }
      }
    }
  }
  if (dests != n) {
    memset(steps, inf, sizeof(steps));
  }
}

int main() {
  while (scanf("%d%d", &n, &m) != EOF) {
    int a, b, c;
    ans = inf;
    for (int i = 0; i < m; i++) {
      scanf("%d%d%d", &a, &b, &c);
      points[a].id = a;
      points[a].roads[b].des = b;
      points[a].roads[b].price = c;
      points[b].id = b;
      points[b].roads[a].des = a;
      points[b].roads[a].price = c;
    }

    for (int i = 1; i <= n; i++) {

      memset(steps, inf, sizeof(steps));
      while (!res.empty()) {
        res.pop();
      }
      bfs(i);
      if (if_all_step()) {
        int step = getstep();
        if (step < ans) {
          ans = step;
        }
      }
    }
    if (ans != inf) {
      printf("%d\n", ans);
    } else {
      printf("-1\n");
    }
  }
  return 0;
}