#include <cstring>
#include <iostream>
#include <memory>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
int N, M;
class UF {
public:
  UF(int n) {
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

private:
  int count;
  vector<int> parents;
};
int main() {
  cin >> N >> M;
  int s, t;
  UF uf(N);
  for (int i = 0; i < M; i++) {
    cin >> s >> t;
    uf.conn(s, t);
  }
  int begin, end;
  cin >> begin >> end;
  int ans = uf.uni(begin, end) ? 1 : 0;
  cout << ans;
  return 0;
}