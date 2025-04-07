#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int C;
int N;
int W[101];
int V[101];
int K[101];
int dp[2001];
int main() {
  memset(dp, 0, sizeof(dp));
  cin >> C >> N;
  for (int i = 0; i < N; i++) {
    cin >> W[i];
  }
  for (int i = 0; i < N; i++) {
    cin >> V[i];
  }
  for (int i = 0; i < N; i++) {
    cin >> K[i];
  }
  for (int i = 0; i < N; i++) {
    for (int k = 0; k < K[i]; k++) {
      for (int j = C; j >= 0; j--) {
        if (j >= W[i]) {
          dp[j] = max(dp[j], dp[j - W[i]] + V[i]);
        }
      }
    }
  }
  cout << dp[C];
}