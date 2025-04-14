#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int V, E;
vector<vector<int>> g;
vector<int> dist;
vector<bool> visit;
const int inf = 0x3f3f3f3f;
int main() {
  cin >> V >> E;
  dist.resize(V + 1, inf);
  visit.resize(V + 1, false);
  g.resize(V + 1, vector<int>(V + 1, inf));
  for (int i = 1; i <= V; i++) {
    g[i][i] = 0;
  }
  int b = 0;
  int e = 0;
  int value = 0;
  for (int i = 0; i < E; i++) {
    cin >> b >> e >> value;
    g[b][e] = min(g[b][e], value);
    g[e][b] = min(g[e][b], value);
  }
  int ans = 0;
  visit[1] = true;
  dist[1] = 0;
  for (int i = 1; i <= V; i++) {
    dist[i] = min(g[i][1], dist[i]);
  }
  for (int i = 0; i < V - 1; i++) {
    int cur = -1;
    for (int j = 1; j <= V; j++) {
      if (!visit[j] && (cur == -1 || dist[j] < dist[cur])) {
        cur = j;
      }
    }

    ans += dist[cur];
    visit[cur] = true;
    for (int j = 1; j <= V; j++) {
      if (!visit[j]) {
        dist[j] = min(dist[j], g[j][cur]);
      }
    }
  }
  cout << ans;
  return 0;
}