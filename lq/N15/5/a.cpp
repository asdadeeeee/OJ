#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <memory>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;
int n, m;
bool visit[10001];
vector<int> A;
bool bound(int x) { return x >= 0 && x < n; }
int dx[2] = {-1, 1};

int findnextidx(int cur, int i) {
  if (i == 1) {

    while (cur < n && visit[cur]) {
      cur++;
    }
    return cur == n ? -1 : cur;
  }
  if (i == -1) {
    while (cur >= 0 && visit[cur]) {
      cur--;
    }
    return cur == -1 ? -1 : cur;
  }
}
int dfs(int cur, int k) {
  visit[cur] = true;
  int res = 1;
  int temp = 0;
  for (int i = 0; i < 2; i++) {
    int nextidx = findnextidx(cur, dx[i]);
    if (nextidx != -1) {
      int distance = abs(A[cur] - A[nextidx]);
      if (distance <= k) {
        temp = max(temp, dfs(nextidx, k - distance));
      }
    }
  }
  return res + temp;
}
int main() {
  cin >> n >> m;
  A.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  sort(A.begin(), A.end(), greater<int>());
  int begin1 = 0;
  int begin2 = 0;
  int idx = 0;
  for (idx = 0; idx < n; idx++) {
    if (A[idx] >= 0) {
      break;
    }
  }
  int ans = 0;
  if (idx == n - 1 || idx == 0 || A[idx] == 0) {
    memset(visit, false, sizeof(visit));
    ans = dfs(idx, m);

  } else {
    begin2 = idx;
    begin1 = idx - 1;
    memset(visit, false, sizeof(visit));
    int v1 = dfs(begin1, m);
    memset(visit, false, sizeof(visit));
    int v2 = dfs(begin2, m);
    ans = max(v1, v2);
  }
  cout << ans;
  return 0;
}