#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int N;
int A[111][111];
bool in[111];
int dist[111];
const int inf = 0x3f3f3f3f;
void dij() {
  for (int i = 1; i < N; i++) {
    int t = -1;
    int min = 0x3f3f3f3f;
    for (int j = 1; j < N; j++) {
      if (!in[j] && dist[j] < min) {
        min = dist[j];
        t = j;
      }
    }
    in[t] = true;
    if (t == -1) {
      return;
    }
    for (int j = 0; j < N; j++) {
      if (!in[j] && dist[t] + A[t][j] < dist[j]) {
        dist[j] = dist[t] + A[t][j];
      }
    }
  }
}
int main() {
  cin >> N;
  memset(A, inf, sizeof(A));
  memset(in, false, sizeof(in));
  memset(dist, inf, sizeof(dist));
  int t;
  char ch;
  for (int i = 1; i < N; i++) {
    for (int j = 0; j < i; j++) {
      t = inf;
      if (!scanf("%d", &t)) {
        scanf("%c", &ch);
      }
      if (t != inf) {
        A[i][j] = t;
        A[j][i] = t;
      }
    }
  }
  for (int i = 0; i < N; i++) {
    A[i][i] = 0;
    dist[i] = A[0][i];
  }
  in[0] = true;
  dij();
  int ans = 0;
  for (int i = 0; i < N; i++) {
    ans = max(ans, dist[i]);
  }
  cout << ans << endl;
}
