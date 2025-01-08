#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int N, M, X;
int A[1001][1001];
int B[1001][1001];
const int inf = 0x3f3f3f3f;

int dij(int s) {
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> qa;
  int distA[1001];
  memset(distA, inf, sizeof(distA));
  distA[s] = 0;
  qa.push({0, s});
  while (!qa.empty()) {
    auto cur = qa.top();
    qa.pop();
    if (cur.first > distA[cur.second]) {
      continue;
    }
    for (int i = 1; i <= N; i++) {
      if (distA[i] > cur.first + A[cur.second][i]) {
        distA[i] = cur.first + A[cur.second][i];
        qa.emplace(distA[i], i);
      }
    }
  }

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> qb;
  int distB[1001];
  memset(distB, inf, sizeof(distB));
  distB[s] = 0;
  qb.push({0, s});
  while (!qb.empty()) {
    auto cur = qb.top();
    qb.pop();
    if (cur.first > distB[cur.second]) {
      continue;
    }
    for (int i = 1; i <= N; i++) {
      if (distB[i] > cur.first + B[cur.second][i]) {
        distB[i] = cur.first + B[cur.second][i];
        qb.emplace(distB[i], i);
      }
    }
  }

  int m = 0;
  for (int i = 1; i <= N; i++) {
    m = max(m, distA[i] + distB[i]);
  }

  return m;
}
int main() {
  cin >> N >> M >> X;
  memset(A, inf, sizeof(A));
  memset(B, inf, sizeof(B));
  for (int i = 1; i <= N; i++) {
    A[i][i] = 0;
    B[i][i] = 0;
  }
  while (M--) {
    int s, t, dist;
    cin >> s >> t >> dist;
    A[s][t] = min(A[s][t], dist);
    B[t][s] = min(B[t][s], dist);
  }
  cout << dij(X);
}