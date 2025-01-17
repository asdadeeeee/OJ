#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
using namespace std;

int N, M, W;
int A[510][510];
const int inf = 0x3f3f3f3f;

bool floyd() {
  for (int k = 1; k <= N; k++) {
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        if (A[i][j] > A[i][k] + A[k][j]) {
          A[i][j] = A[i][k] + A[k][j];
        }
      }
      if (A[i][i] < 0) {
        return true;
      }
    }
  }
  return false;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int F;
  cin >> F;
  while (F--) {
    cin >> N >> M >> W;
    // memset(A, inf, sizeof(A));
    for (int i = 1; i <= N; ++i) {
      for (int j = 1; j <= N; ++j) {
        A[i][j] = inf;
      }
    }

    for (int i = 1; i <= N; i++) {
      A[i][i] = 0;
    }
    int s = 0;
    int t = 0;
    int dist = 0;
    for (int i = 0; i < M; i++) {

      cin >> s >> t >> dist;
      A[s][t] = A[t][s] = min(A[s][t], dist);
    }
    for (int i = 0; i < W; i++) {
      cin >> s >> t >> dist;
      A[s][t] = -dist;
    }
    cout << (floyd() ? "YES" : "NO") << endl;
  }
}