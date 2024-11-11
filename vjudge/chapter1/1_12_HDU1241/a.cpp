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

  bool operator<(const point &other) const {
    // 优先比较 x 坐标
    if (x != other.x) {
      return x < other.x;
    }
    // 如果 x 坐标相等，则比较 y 坐标
    return y < other.y;
  }
};
std::queue<point> points;
int m, n;
std::map<int, set<point>> oils;
int global_oil_id = 0;
int ans = 0;
void printA(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << A[i][j];
    }
    cout << endl;
  }
}
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
int combine_oil(set<int> oil_ids) {
  if (oil_ids.size() > 1) {
    auto oil_id_iter = oil_ids.begin();
    int dest_oil_id = *oil_id_iter;
    auto dest_oil = oils.find(dest_oil_id);
    oil_id_iter++;
    for (; oil_id_iter != oil_ids.end(); oil_id_iter++) {
      auto oil = oils.find(*oil_id_iter);
      for (const auto &p : oil->second) {
        dest_oil->second.insert(p);
      }
      oils.erase(oil);
    }
  }
  return *oil_ids.begin();
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
      if (bound(ns)) {
        take[nx][ny] = true;
        points.push(ns);
      }
    }
    if (if_oil(cur_p)) {
      std::set<int> oil_ids;
      for (int i = 0; i < 8; i++) {
        int nx = cur_p.x + dx[i];
        int ny = cur_p.y + dy[i];
        point ns{nx, ny};
        if (bound(ns)) {
          take[nx][ny] = true;
          points.push(ns);
        }
        if (if_oil(ns)) {

          for (const auto &oil : oils) {
            if (oil.second.find(ns) != oil.second.end()) {
              oil_ids.insert(oil.first);
            }
            // for (const auto &o : oil.second) {
            //   if (o.x == ns.x && o.y == ns.y){}
            // }
          }
        }
      }
      if (oil_ids.empty()) {
        set<point> new_oil;
        new_oil.insert(cur_p);

        int new_oil_id = global_oil_id++;
        oils.insert(std::make_pair(new_oil_id, new_oil));
      } else {
        int oil_id = combine_oil(oil_ids);
        oils.find(oil_id)->second.insert(cur_p);
      }
    }
  }
}
int main() {

  while (true) {
    while (!points.empty()) {
      points.pop();
    }
    oils.clear();
    global_oil_id = 0;
    memset(take, 0, sizeof(take));
    cin >> m >> n;
    if (m == 0 || n == 0) {
      break;
    }
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        cin >> A[i][j];
      }
    }
    point start{0, 0};
    bfs(start);
    cout << oils.size() << endl;
    // printA(n);
  }
  // printAns();

  return 0;
}
