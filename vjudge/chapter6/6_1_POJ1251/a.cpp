#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

class UT {
public:
  UT(int num) {
    n = num;
    count = num;
    parents.resize(n);
    for (int i = 0; i < num; i++) {
      parents[i] = i;
    }
  }

  int findp(int n) {
    if (n != parents[n]) {
      parents[n] = findp(parents[n]);
    }
    return parents[n];
  }

  bool isconn(int l, int r) {
    int lp = findp(l);
    int rp = findp(r);
    return lp == rp;
  }

  void conn(int l, int r) {
    if (isconn(l, r)) {
      return;
    }
    int lp = findp(l);
    int rp = findp(r);
    parents[lp] = rp;
    count--;
  }

private:
  int n;
  int count;
  vector<int> parents;
};
int N;
const int inf = 0x3f3f3f3f;
struct edge {
  int u;
  int v;
  int dist;
  // 定义一个带有参数的构造函数
  edge(int u, int v, int dist) {
    this->u = u;
    this->v = v;
    this->dist = dist;
  }
};

bool cmp(edge a, edge b) { return a.dist < b.dist; }
int main() {
  vector<edge> edges;
  while (cin >> N && N != 0) {
    edges.clear();
    UT ut(N);
    char begin;
    int m;
    for (int i = 0; i < N - 1; i++) {
      cin >> begin >> m;
      char end;
      int d;
      for (int j = 0; j < m; j++) {
        cin >> end >> d;
        edge e(begin - 'A', end - 'A', d);
        edges.push_back(e);
      }
    }
    std::sort(edges.begin(), edges.end(), cmp);
    int ans = 0;
    for (int i = 0; i < edges.size(); i++) {
      edge e = edges[i];
      if (ut.isconn(e.u, e.v)) {
        continue;
      }
      ut.conn(e.u, e.v);
      ans += e.dist;
    }
    // for (const edge &e : edges) {
    //   if (ut.isconn(e.u, e.v)) {
    //     continue;
    //   }
    //   ut.conn(e.u, e.v);
    //   ans += e.dist;
    // }
    cout << ans << endl;
  }
}