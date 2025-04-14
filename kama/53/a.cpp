#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int V, E;
struct edge {
  int s;
  int e;
  int value;
};
class UF {
public:
  UF(int n) {
    count = n;
    parent.resize(n + 1);
    for (int i = 1; i <= n; i++) {
      parent[i] = i;
    }
  }

  bool uni(int p, int q) { return findr(p) == findr(q); }

  int findr(int p) {
    if (parent[p] != p) {
      parent[p] = findr(parent[p]);
    }
    return parent[p];
  }

  void connect(int p, int q) {
    int rp = findr(p);
    int rq = findr(q);
    if (rp == rq) {
      return;
    }
    parent[rp] = rq;
    count--;
  }
  int getCount() { return count; }

private:
  int count;
  vector<int> parent;
};

struct cmp {
  const bool operator()(const edge &a, const edge &b) {
    return a.value < b.value;
  }
};
int main() {
  cin >> V >> E;
  vector<edge> es;
  for (int i = 0; i < E; i++) {
    edge e;
    cin >> e.s >> e.e >> e.value;
    es.emplace_back(e);
  }
  sort(es.begin(), es.end(), cmp());
  UF uf(V);
  int ans = 0;
  for (int i = 0; i < E; i++) {
    if (uf.getCount() == 1) {
      break;
    }
    auto e = es[i];
    if (uf.uni(e.s, e.e)) {
      continue;
    } else {
      uf.connect(e.s, e.e);
      ans += e.value;
    }
  }
  cout << ans;
  return 0;
}
