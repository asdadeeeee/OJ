#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int N, M;
int A[111][111];
const int inf = 0x3f3f3f3f;
void floyd() {
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      for (int k = 1; k <= N; k++) {
        // if (A[j][i]+A[i][k] < A[j][k]){

        // }
        A[j][k] = min(A[j][i] + A[i][k], A[j][k]);
      }
    }
  }
}
int main() {
  cin >> N >> M;
  memset(A, inf, sizeof(A));
  for (int i = 1; i <= N; i++) {
    A[i][i] = 0;
  }
  for (int i = 0; i < M; i++) {
    int s;
    int t;
    cin >> s >> t;
    A[s][t] = 1;
  }
  floyd();
  int cnt = 0;

  for (int i = 1; i <= N; i++) {
    bool found = true;
    for (int j = 1; j <= N; j++) {
      if (A[i][j] < inf || A[j][i] < inf) {
        continue;
      } else {
        found = false;
        break;
      }
    }
    if (found) {
      cnt++;
    }
  }
  cout << cnt << endl;
}
