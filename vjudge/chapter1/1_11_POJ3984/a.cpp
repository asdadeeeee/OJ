#include <cstdlib>
#include <cstring>
#include <iostream>
#include <ostream>
#include <queue>
#include <vector>

using namespace std;
struct step {
  int x;
  int y;
};
int dx[5] = {-1, 1, 0, 0};
int dy[5] = {0, 0, 1, -1};
std::vector<step> steps;
std::vector<step> ans;

int A[6][6];
int taken[6][6];
int n, k;
int MIN = 0x3f3f3f3f;
void printans() {
  for (int i = 0; i < ans.size(); i++) {
    cout << "(" << ans.at(i).x << ", " << ans.at(i).y << ")" << endl;
  }
}
void printA(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << A[i][j];
    }
    cout << endl;
  }
}
bool bound(step s) {
  if (s.x >= 0 && s.x < 5 && s.y >= 0 && s.y < 5 && A[s.x][s.y] == 0) {
    return true;
  }
  return false;
}

void dfs(step cur_s) {
  if (cur_s.x == 4 && cur_s.y == 4) {
    if (steps.size() < MIN) {
      MIN = steps.size();
      ans = steps;
    }
  }
  for (int i = 0; i < 4; i++) {
    int nx = cur_s.x + dx[i];
    int ny = cur_s.y + dy[i];
    step ns{nx, ny};
    if (bound(ns) && taken[cur_s.x][cur_s.y] + 1 < taken[nx][ny]) {
      steps.push_back(ns);
      taken[nx][ny] = taken[cur_s.x][cur_s.y] + 1;
      dfs(ns);
      steps.pop_back();
    }
  }
}
int main() {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      cin >> A[i][j];
    }
  }
  step start{0, 0};
  memset(taken, 0x3f3f3f3f, sizeof(taken));
  taken[0][0] = 0;

  steps.push_back(start);
  dfs(start);
  if (ans.size() > 0) {
    printans();
  } else {
    cout << -1;
  }

  return 0;
}
