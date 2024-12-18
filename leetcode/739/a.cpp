#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
struct info {
  int temp;
  int n;
};
class Solution {
public:
  vector<int> dailyTemperatures(vector<int> &temperatures) {
    vector<int> res;
    int k = temperatures.size();
    for (int i = k - 1; i >= 0; i--) {
      int t = temperatures[i];
      bool find = true;
      int j = 1;
      while (!h.empty() && h.top().temp <= t) {
        j += h.top().n;
        h.pop();
      }
      if (h.empty()) {
        find = false;
        j = 0;
      }
      res.push_back(j);
      h.push({t, j});
    }
    reverse(res.begin(), res.end());
    return res;
  }

  stack<info> h;
};
