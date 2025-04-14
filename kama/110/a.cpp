#include <cstring>
#include <iostream>
#include <memory>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;
int N;
bool connect[501][501];
bool visit[501];
bool finish[501];
string A[501];
string beginStr;
string endStr;
bool conn(const string &s1, const string &s2) {
  int temp = 0;
  int n = s1.size();
  int m = s2.size();
  if (n != m) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    if (s1[i] != s2[i]) {
      temp++;
    }
    if (temp == 2) {
      return false;
    }
  }
  return true;
}
int main() {
  cin >> N;
  cin >> beginStr >> endStr;
  if (conn(beginStr, endStr)) {
    cout << 1;
    return 0;
  }
  memset(finish, false, sizeof(finish));
  memset(visit, false, sizeof(visit));
  memset(connect, false, sizeof(connect));
  queue<int> q;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  for (int i = 0; i < N; i++) {
    if (conn(A[i], endStr)) {
      finish[i] = true;
    }
    for (int j = i + 1; j < N; j++) {
      if (conn(A[i], A[j])) {
        connect[i][j] = true;
        connect[j][i] = true;
      } else {
        connect[i][j] = false;
        connect[j][i] = false;
      }
    }
  }
  int path = 0;
  q.push(-1);

  while (!q.empty()) {
    int n = q.size();
    path++;
    for (int i = 0; i < n; i++) {
      int cur = q.front();
      q.pop();
      if (cur == -1) {

        for (int j = 0; j < N; j++) {
          if (conn(beginStr, A[j])) {
            q.push(j);
            visit[j] = true;
          }
        }
      } else {
        if (finish[cur]) {
          cout << path + 1;
          return 0;
        }
        for (int j = 0; j < N; j++) {
          if (cur != j && !visit[j] && connect[cur][j]) {
            q.push(j);
            visit[j] = true;
          }
        }
      }
    }
  }
  cout << 0;
  return 0;
}