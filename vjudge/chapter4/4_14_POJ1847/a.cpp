#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
int N, A, B;
int M[101][101];
const int inf = 0x3f3f3f3f;
int dist[101];
bool in[101];
void dij() {
  for (int i = 1; i < N; i++) {
    int min = inf;
    int t = -1;
    for (int j = 1; j <= N; j++) {
      if (!in[j] && dist[j] < min) {
        t = j;
        min = dist[j];
      }
    }
    if (t == -1) {
      return;
    }
    in[t] = true;
    for (int j = 1; j <= N; j++) {
      if (!in[j]) {
        dist[j] = std::min(dist[j], dist[t] + M[t][j]);
      }
    }
  }
}

int main() {
  cin >> N >> A >> B;
  memset(M, inf, sizeof(M));
  memset(dist, inf, sizeof(dist));
  memset(in, false, sizeof(in));
  for (int i = 1; i <= N; i++) {
    M[i][i] = 0;
    int t = 0;
    cin >> t;
    int dest = 0;
    for (int j = 0; j < t; j++) {
      cin >> dest;
      if (j == 0) {
        M[i][dest] = 0;
      } else {
        M[i][dest] = 1;
      }
    }
  }
  in[A] = true;
  for (int i = 1; i <= N; i++) {
    dist[i] = min(M[A][i], inf);
  }
  dij();
  if (dist[B] == inf) {
    cout << -1 << endl;
  } else {
    cout << dist[B] << endl;
  }
  return 0;
}