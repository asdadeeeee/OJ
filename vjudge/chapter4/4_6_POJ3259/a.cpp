#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int F;
int N, M, W;
int A[501][501];
const int inf = 0x3f3f3f3f;

bool floyd() {
  for (int k = 1; k <= N; k++) {
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        A[i][j] = min(A[i][j], A[i][k] + A[k][j]);
      }
      if (A[i][i] < 0) {
        return true;
      }
    }
  }
  return false;
}
int main() {
  cin >> F;
  while (F--) {
    cin >> N >> M >> W;
    memset(A, inf, sizeof(A));
    for (int i = 1; i <= N; i++) {
      A[i][i] = 0;
    }
    for (int i = 0; i < M; i++) {
      int s = 0;
      int t = 0;
      int dist = 0;
      cin >> s >> t >> dist;
      A[s][t] = min(A[s][t], dist);
      A[t][s] = A[s][t];
    }
    for (int i = 0; i < W; i++) {
      int s = 0;
      int t = 0;
      int dist = 0;
      cin >> s >> t >> dist;
      A[s][t] = min(A[s][t], 0 - dist);
    }
    if (floyd()) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}