#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class cmp {
public:
  inline bool operator()(const vector<int> &e1, const vector<int> &e2) const {
    return e1[0] < e2[0] || (e1[0] == e2[0] && e1[1] > e2[1]);
  }
};
class Solution {
public:
  int maxEnvelopes(vector<vector<int>> &envelopes) {

    sort(envelopes.begin(), envelopes.end(), cmp());

    int n = envelopes.size();
    vector<int> dp{envelopes[0][1]};
    dp.reserve(envelopes.size());
    for (int i = 1; i < n; i++) {
      int num = envelopes[i][1];
      if (num > dp.back()) {
        dp.emplace_back(num);
      } else {
        auto it = lower_bound(dp.begin(), dp.end(), num);
        *it = num;
      }
    }

    return dp.size();
  }
};

int main() {
  vector<vector<int>> envelopes = {{17, 15}, {17, 18}, {2, 8}, {7, 2},
                                   {17, 2},  {17, 8},  {6, 15}};
  Solution so;
  cout << so.maxEnvelopes(envelopes);
}