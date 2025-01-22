#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int calculateMinimumHP(vector<vector<int>> &dungeon) {
    int inf = 0x3f3f3f3f;
    int n = dungeon.size();
    int m = dungeon[0].size();
    vector<int> dp(m + 1, inf);
    dp[m] = 1;
    for (int i = n - 1; i >= 0; i--) {
      for (int j = m - 1; j >= 0; j--) {
        int min_hp = min(dp[j], dp[j + 1]);
        dp[j] = max(1, min_hp - dungeon[i][j]);
      }
      dp[m] = inf;
    }
    return dp[0];
  }
};

int main() {
  vector<vector<int>> dungeon = {{1, -3, 3}, {0, -2, 0}, {-3, -3, -3}};
  Solution so;
  cout << so.calculateMinimumHP(dungeon);
}