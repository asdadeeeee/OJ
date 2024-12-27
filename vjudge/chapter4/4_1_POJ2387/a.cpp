#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int T, N;
int inf = 0x3f3f3f3f;
int dis[2001];
int road[2001][2001];
bool visited[2001];

void dijsk(int start) {
  dis[start] = 0;

  for (int i = 0; i < N - 1; i++) {
    int cur = -1;
    for (int j = 1; j <= N; j++) {
      if (!visited[j] && (cur == -1 || dis[j] < dis[cur])) {
        cur = j;
      }
    }
    for (int j = 1; j <= N; j++) {
      dis[j] = min(dis[j], dis[cur] + road[cur][j]);
    }
    visited[cur] = true;
  }
}
int main() {
  cin >> T >> N;
  memset(road, inf, sizeof(road));
  memset(visited, false, sizeof(visited));
  memset(dis, inf, sizeof(dis));
  for (int i = 0; i < T; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    road[a][b] = min(c, road[a][b]);
    road[b][a] = road[a][b];
  }
  dijsk(1);
  cout << dis[N] << endl;
}