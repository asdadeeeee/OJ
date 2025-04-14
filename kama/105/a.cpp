#include <cstring>
#include <iostream>
#include <memory>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
int N, K;
vector<bool> visit;
unordered_map<int, vector<int>> A;
int main() {
  cin >> N >> K;
  visit.resize(N + 1, false);
  int s, t;
  for (int i = 0; i < K; i++) {
    cin >> s >> t;
    A[s].emplace_back(t);
  }
  queue<int> q;
  q.push(1);
  visit[1] = true;
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (auto next : A[cur]) {
      if (!visit[next]) {
        q.push(next);
        visit[next] = true;
      }
    }
  }
  bool ans = true;
  for (int i = 1; i <= N; i++) {
    if (!visit[i]) {
      ans = false;
      break;
    }
  }
  int res = ans ? 1 : -1;
  cout << res;
  return 0;
}