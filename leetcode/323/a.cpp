
#include <vector>
using namespace std;

class UF {
public:
  UF(int n) {
    count_ = n;
    parent.resize(n);
    for (int i = 0; i < n; i++) {
      parent[i] = i;
    }
  };

  void uni(int p, int q) {
    int rp = findroot(p);
    int rq = findroot(q);
    if (p == q) {
      return;
    }
    parent[rp] = rq;
    count_--;
  }

  int findroot(int p) {
    while (parent[p] != p) {
      parent[p] = findroot(parent[p]);
    }
    return parent[p];
  }

  int getcount() { return count_; }

private:
  int count_;
  vector<int> parent;
};
class Solution {
public:
  int countComponents(int n, vector<vector<int>> &edges) {
    UF uf(n);
    for (auto e : edges) {
      uf.uni(e[0], e[1]);
    }
    return uf.getcount();
  }
};
