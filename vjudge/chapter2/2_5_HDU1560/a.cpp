#include <cstring>
#include <iostream>
#include <memory>
#include <queue>
#include <vector>
#define MAXN 10
using namespace std;

const int inf = 0x3f3f3f3f;
int n, t;
int deep = 0;

struct seq {
  char ch[MAXN];
  int len;
};

int pos[MAXN];
int ans = 0;
char c[4] = {'A', 'C', 'G', 'T'};
seq seqs[MAXN];
int eval() {
  int res = 0;
  for (int i = 0; i < n; i++) {
    res = max(res, seqs[i].len - pos[i]);
  }
  return res;
}
void dfs(int step) {
  if (step + eval() > deep) {
    return;
  }
  if (eval() == 0) {
    ans = step;
    return;
  }
  int pre[MAXN];
  for (int i = 0; i < 4; i++) {
    bool flag = false;
    for (int j = 0; j < n; j++) {
      pre[j] = pos[j];
      if (seqs[j].ch[pos[j]] == c[i]) {
        flag = true;
        pos[j]++;
      }
    }
    if (flag) {
      dfs(step + 1);
      if (ans) {
        return;
      }
      for (int j = 0; j < n; j++) {
        pos[j] = pre[j];
      }
    }
  }
  return;
}
int main() {
  cin >> t;
  while (t--) {
    ans = 0;
    cin >> n;
    deep = 0;
    memset(pos, 0, sizeof(pos));
    for (int i = 0; i < n; i++) {
      cin >> seqs[i].ch;
      seqs[i].len = strlen(seqs[i].ch);
      deep = max(deep, seqs[i].len);
    }
    while (true) {
      dfs(0);
      if (ans) {
        break;
      }
      deep++;
    }
    cout << ans << endl;
  }
}