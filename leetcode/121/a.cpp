#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;
class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int low = 0x3f3f3f3f;
    int ans = 0;
    int n = prices.size();
    for (int i = 0; i < n; i++) {
      low = min(low, prices[i]);
      ans = max(ans, prices[i] - low);
    }
    return ans;
  }
};