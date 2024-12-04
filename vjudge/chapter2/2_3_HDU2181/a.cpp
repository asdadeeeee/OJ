#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int inf = 0x3f3f3f3f;

struct Point {
  int self;
  int a;
  int b;
  int c;
};

Point all_points[21];
int step[21];
std::vector<int> res;
int start = 0;

std::vector<std::vector<int>> ans;

bool if_all_step() {
  for (int i = 1; i <= 20; i++) {
    if (step[i] == 0) {
      return false;
    }
  }
  return true;
}
void dfs(int cur) {

  if (cur == start && step[cur] == 2) {
    ans.emplace_back(res);
    return;
  }
  for (int i = 0; i < 3; i++) {
    int next = 0;
    switch (i) {
    case 0: {
      next = all_points[cur].a;
      break;
    }
    case 1: {
      next = all_points[cur].b;
      break;
    }
    case 2: {
      next = all_points[cur].c;
      break;
    }
    }
    if (next != start) {
      if (step[next] == 0) {
        step[next]++;
        res.push_back(next);
        dfs(next);
        step[next]--;
        res.pop_back();
      }
    } else {
      if (step[next] == 1 && if_all_step()) {
        step[next]++;
        res.push_back(next);
        dfs(next);
        step[next]--;
        res.pop_back();
      }
    }
  }
}
void printres(std::vector<int> &res) {
  for (int i = 0; i < res.size(); i++) {
    cout << res.at(i) << " ";
  }
  cout << endl;
}
int main() {
  for (int i = 1; i <= 20; i++) {
    all_points[i].self = i;
    cin >> all_points[i].a;
    cin >> all_points[i].b;
    cin >> all_points[i].c;
  }
  while (true) {
    ans.clear();
    res.clear();
    memset(step, 0, sizeof(step));

    cin >> start;
    if (start == 0) {
      break;
    }
    step[start] = 1;
    res.push_back(start);
    dfs(start);
    int idx = 0;
    for (int i = 0; i < ans.size(); i++) {
      cout << i + 1 << ":  ";
      printres(ans.at(i));
    }
  }
  return 0;
}