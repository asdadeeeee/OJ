#include <vector>
using namespace std;
class Solution {
public:
  int minCostClimbingStairs(vector<int> &cost) {
    int c0 = cost[0];
    int c1 = cost[1];
    int c2 = 0;
    int n = cost.size();
    if (n == 1) {
      return cost[0];
    }
    if (n == 2) {
      return min(cost[0], cost[1]);
    }
    for (int i = 0; i <= n - 2; i++) {
      if (i == n - 2) {
        c2 = min(c0, c1);
        break;
      }
      c2 = min(c0, c1) + cost[i + 2];
      c0 = c1;
      c1 = c2;
    }
    return c2;
  }
};
int main() {
  Solution so;
  vector<int> cost{10, 15, 20};
  so.minCostClimbingStairs(cost);
}