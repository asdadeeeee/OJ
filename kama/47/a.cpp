#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int N, M;
vector<vector<int>> g;
vector<bool> visit;
vector<int> dist;
const int inf = 0x3f3f3f3f;
int main() {

  cin >> N >> M;
  g.resize(N + 1, vector<int>(N + 1, inf));
  visit.resize(N + 1, false);
  dist.resize(N + 1, inf);
  for (int i = 1; i <= N; i++) {
    g[i][i] = 0;
  }

  for (int i = 0; i < M; i++) {
    int b = 0;
    int e = 0;
    int value = 0;
    cin >> b >> e >> value;
    g[b][e] = min(g[b][e], value);
  }
  visit[1] = true;
  dist[1] = 0;
  for (int i = 1; i <= N; i++) {
    dist[i] = min(dist[i], g[1][i]);
  }
  for (int i = 0; i < N - 1; i++) {
    int cur = -1;
    for (int j = 1; j <= N; j++) {
      if (!visit[j] && (cur == -1 || dist[j] < dist[cur])) {
        cur = j;
      }
    }
    visit[cur] = true;
    for (int j = 1; j <= N; j++) {
      if (!visit[j]) {
        dist[j] = min(dist[j], dist[cur] + g[cur][j]);
      }
    }
  }
  int ans = dist[N] == inf ? -1 : dist[N];
  cout << ans;
  return 0;
}
