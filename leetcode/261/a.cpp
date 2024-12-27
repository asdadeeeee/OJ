#include <vector>
using namespace std;
class UF {
public:
  UF(int n) {
    cnt = 0;
    parents.resize(n);
    for (int i = 0; i < n; i++) {
      parents[i] = i;
    }
  }

  int findp(int n) {
    if (parents[n] != n) {
      parents[n] = findp(parents[n]);
    }
    return parents[n];
  }

  bool connec(int p, int q) {
    int rp = findp(p);
    int rq = findp(q);
    return rp == rq;
  }

  void uni(int p, int q) {
    int rp = findp(p);
    int rq = findp(q);
    if (rp == rq) {
      return;
    }
    parents[rp] = rq;
    cnt--;
  }

  std::vector<int> parents;
  int cnt = 0;
};
class Solution {

public:
  bool validTree(int n, vector<vector<int>> &edges) {
    UF uf(n);
    for (auto &e : edges) {
      int p = e[0];
      int q = e[0];
      if (uf.connec(p, q)) {
        return false;
      }
      uf.uni(p, q);
    }
    return uf.cnt == 1;
  }
};