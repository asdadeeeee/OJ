#include <vector>
using namespace std;
class Solution {
public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int n = gas.size();
    int cur = 0;
    int total = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      cur += gas[i] - cost[i];
      total += gas[i] - cost[i];
      if (cur < 0) {
        ans = i + 1;
        cur = 0;
      }
    }
    if (total < 0) {
      return -1;
    }
    return ans;
  }
};
int main() {
  Solution so;
  vector<int> gas = {2, 3, 4};
  vector<int> cost = {3, 4, 3};
  so.canCompleteCircuit(gas, cost);
}