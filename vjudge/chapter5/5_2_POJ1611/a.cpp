#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int n, m;
class UT {
public:
  UT(int n) {
    for (int i = 0; i < n; i++) {
      parent[i] = i;
    }
    cnt = n;
  }

  int findp(int t) {
    if (t != parent[t]) {
      parent[t] = findp(parent[t]);
    }
    return parent[t];
  }
  bool con(int a, int b) {
    int pa = findp(a);
    int pb = findp(b);
    return pa == pb;
  }
  void uni(int a, int b) {
    int pa = findp(a);
    int pb = findp(b);
    if (pa == pb) {
      return;
    }
    parent[pa] = pb;
    cnt--;
  }

private:
  int cnt;
  int parent[30001];
};
int main() {
  while (cin >> n >> m) {
    if (n == 0 && m == 0) {
      break;
    }
    UT ut(n);
    while (m--) {
      int num = 0;
      cin >> num;
      int stu[num];
      for (int i = 0; i < num; i++) {
        cin >> stu[i];
        ut.uni(stu[0], stu[i]);
      }
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
      if (ut.con(0, i)) {
        sum++;
      }
    }
    cout << sum << endl;
  }
}