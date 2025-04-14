#include <cstring>
#include <iostream>
#include <memory>
#include <queue>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;
int N;
class UF {
public:
  UF(int n) {
    count = n;
    parents.resize(n + 1);
    for (int i = 1; i <= n; i++) {
      parents[i] = i;
    }
  }
  void init(int n) {
    count = n;
    parents.resize(n + 1);
    for (int i = 1; i <= n; i++) {
      parents[i] = i;
    }
  }
  int findp(int x) {
    if (parents[x] != x) {
      parents[x] = findp(parents[x]);
    }
    return parents[x];
  }

  bool uni(int p, int q) {
    int rp = findp(p);
    int rq = findp(q);
    return rp == rq;
  }

  void conn(int p, int q) {
    int rp = findp(p);
    int rq = findp(q);
    if (rp == rq) {
      return;
    }
    parents[rp] = rq;
  }

  int getCount() { return count; }

  bool remove(const vector<pair<int, int>> &edges, int N, int remove_edge_idx) {
    init(N);
    for (int i = 0; i < N; i++) {
      if (i == remove_edge_idx) {
        continue;
      }
      if (uni(edges[i].first, edges[i].second)) {
        return false;
      }
      conn(edges[i].first, edges[i].second);
    }
    return true;
  }

  int findedge(const vector<pair<int, int>> &edges, int N) {
    init(N);
    for (int i = 0; i < N; i++) {
      if (uni(edges[i].first, edges[i].second)) {
        return i;
      }
      conn(edges[i].first, edges[i].second);
    }
    return -1;
  }

private:
  int count;
  vector<int> parents;
};

int main() {
  cin >> N;
  UF uf(N);
  int s, t;
  vector<int> indegree(N + 1, 0);
  vector<pair<int, int>> edges;
  for (int i = 1; i <= N; i++) {
    cin >> s >> t;
    edges.push_back({s, t});
    indegree[t]++;
  }
  vector<int> in2edgevec;
  for (int i = N - 1; i >= 0; i--) {
    if (indegree[edges[i].second] == 2) {
      in2edgevec.emplace_back(i);
    }
  }
  if (!in2edgevec.empty()) {
    if (uf.remove(edges, N, in2edgevec[0])) {
      cout << edges[in2edgevec[0]].first << " " << edges[in2edgevec[0]].second;
    } else {
      cout << edges[in2edgevec[1]].first << " " << edges[in2edgevec[1]].second;
    }
    return 0;
  }
  int idx = uf.findedge(edges, N);
  cout << edges[idx].first << " " << edges[idx].second;

  return 0;
}