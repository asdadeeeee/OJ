#include <cstring>
#include <iostream>
#include <memory>
#include <queue>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;
int N, M;
unordered_map<int, vector<int>> childs;
vector<int> roots;
vector<int> indgree;
vector<bool> visit;
int main() {
  cin >> N >> M;
  indgree.resize(N, 0);
  visit.resize(N, false);
  int s, t;
  for (int i = 0; i < M; i++) {
    cin >> s >> t;
    indgree[t]++;
    childs[s].emplace_back(t);
  }
  vector<int> ans;
  queue<int> q;
  for (int i = 0; i < N; i++) {
    if (indgree[i] == 0) {
      q.push(i);
      visit[i] = true;
    }
  }
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    ans.emplace_back(cur);
    for (auto n : childs[cur]) {
      indgree[n]--;
      if (indgree[n] == 0 && !visit[n]) {
        q.push(n);
      }
    }
  }
  int si = ans.size();
  if (si != N) {
    cout << -1;
    return 0;
  }
  for (int i = 0; i < si - 1; i++) {
    cout << ans[i] << " ";
  }
  cout << ans[si - 1];

  return 0;
}