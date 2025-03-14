#include <algorithm>
#include <cstring>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;

int M, N;
int weight[5001];
int value[5001];

int dp[5001][5001];
int main() {
  cin >> M >> N;
  for (int i = 0; i < M; i++) {
    cin >> weight[i];
  }
  for (int i = 0; i < M; i++) {
    cin >> value[i];
  }
  memset(dp, 0, sizeof(dp));
  for (int i = 1; i <= M; i++) {
    for (int j = 0; j <= N; j++) {
      if (j >= weight[i - 1]) {
        dp[i][j] =
            max(dp[i - 1][j], dp[i - 1][j - weight[i - 1]] + value[i - 1]);
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }
  cout << dp[M][N] << endl;
  return 0;
}