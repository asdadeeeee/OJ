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

int dp[5001];
int main() {
  cin >> M >> N;
  for (int i = 0; i < M; i++) {
    cin >> weight[i];
  }
  for (int i = 0; i < M; i++) {
    cin >> value[i];
  }
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < M; i++) {
    for (int j = N; j >= weight[i]; j--) {
      dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
    }
  }
  cout << dp[N] << endl;
  return 0;
}