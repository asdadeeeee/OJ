#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int N, M, Q;
vector<vector<int>> g;
vector<vector<int>> dist;
const int inf = 0x3f3f3f3f;
int main() {
  cin >> N >> M;
  g.resize(N + 1, vector<int>(N + 1, inf));
  dist.resize(N + 1, vector<int>(N + 1, inf));
  int p;
  int q;
  int value;
  for (int i = 0; i < M; i++) {
    cin >> p >> q >> value;
    g[p][q] = min(g[p][q], value);
    g[q][p] = min(g[q][p], value);
    dist[p][q] = min(dist[p][q], value);
    dist[q][p] = min(dist[q][p], value);
  }
  for (int i = 1; i <= N; i++) {
    dist[i][i] = 0;
  }

  for (int k = 1; k <= N; k++) {
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
      }
    }
  }
  cin >> Q;
  while (Q--) {
    int begin;
    int end;
    cin >> begin >> end;
    int res = dist[begin][end] == inf ? -1 : dist[begin][end];
    cout << res << endl;
  }
  return 0;
}
