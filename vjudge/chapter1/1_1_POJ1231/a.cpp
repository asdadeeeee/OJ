#include <cstdlib>
#include <iostream>
#include <ostream>
#include <vector>

using namespace std;

char A[10][10];
bool col[10];
int n, k;
int ans = 0;
void printA(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << A[i][j];
    }
    cout << endl;
  }
}
// void func(int n, int k, int &ans) {
//   int begin_a = 0;
//   if (takens.empty()) {
//     begin_a = 0;
//   } else {
//     begin_a = takens.back().x + 1;
//   }
//   for (int a = begin_a; a < n; a++) {
//     for (int b = 0; b < n; b++) {
//       if (CanBeTake(a, b)) {
//         Taken taken{a, b};
//         takens.push_back(taken);
//         if (takens.size() == k) {
//           ans++;
//         }
//         if (takens.size() < k) {
//           func(n, k, ans);
//         }
//         takens.pop_back();
//       }
//     }
//   }
// }
// int resolve(int n, int k) {
//   int res = 0;
//   func(n, k, res);
//   return res;
// }

void dfs(int row, int taken) {
  if (taken == k) {
    ans++;
    return;
  }
  if (row == n) {
    return;
  }
  for (int i = 0; i < n; i++) {
    if (col[i] || A[row][i] == '.') {
      continue;
    }
    col[i] = true;
    dfs(row + 1, taken + 1);
    col[i] = false;
  }
  dfs(row + 1, taken);
}
int main() {

  while (true) {
    ans = 0;
    cin >> n >> k;
    if (n == -1 || k == -1) {
      break;
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> A[i][j];
      }
    }
    dfs(0, 0);
    cout << ans << endl;
    // printA(n);
  }
  // printAns();

  return 0;
}
