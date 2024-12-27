#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

class UF {
public:
  UF(int n) {
    cnt = n;
    parents.resize(n);
    size.resize(n);
    for (int i = 0; i < n; i++) {
      parents[i] = i;
      size[i] = 1;
    }
  }

  int findp(int n) {
    if (parents[n] != n) {
      parents[n] = findp(parents[n]);
    }
    return parents[n];
  }

  bool connect(int p, int q) { return findp(p) == findp(q); }

  void uni(int p, int q) {
    int rp = findp(p);
    int rq = findp(q);
    if (rp == rq) {
      return;
    }
    if (size[rp] < size[rq]) {
      parents[rp] = rq;
      size[rq] += size[rp];
    } else {
      parents[rq] = rp;
      size[rp] += size[rq];
    }
    cnt--;
  }
  int cnt = 0;
  vector<int> parents;
  vector<int> size;
};

struct edge {
  int u;
  int v;
  int dis;
};
class Solution {
public:
  int minCostConnectPoints(vector<vector<int>> &points) {
    vector<edge> edges;
    for (int i = 0; i < points.size(); i++) {
      for (int j = i + 1; j < points.size(); j++) {
        int xi = points[i][0];
        int xj = points[i][1];
        int yi = points[j][0];
        int yj = points[j][1];
        int dis = abs(xi - yi) + abs(xj - yj);
        edges.emplace_back(i, j, dis);
      }
    }
    std::sort(edges.begin(), edges.end(),
              [&](auto a, auto b) { return a.dis < b.dis; });
    UF uf(points.size());
    int ans = 0;
    for (auto &e : edges) {
      int u = e.u;
      int v = e.v;
      if (uf.connect(u, v)) {
        continue;
      }
      uf.uni(u, v);
      ans += e.dis;
    }
    return uf.cnt == 1 ? ans : -1;
  }
};

int main() {
  vector<vector<int>> points = {{0, 0}, {2, 2}};
  Solution so;
  cout << so.minCostConnectPoints(points);
}