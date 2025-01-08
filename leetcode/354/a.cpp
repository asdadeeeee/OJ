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
  //   struct env {
  //     int w;
  //     int h;
  //     env() {}
  //     env(int w_, int h_) {
  //       w = w_;
  //       h = h_;
  //     }
  //     bool operator<(const env &b) { return w < b.w || w == b.w && h > b.h; }
  //   };
  int maxEnvelopes(vector<vector<int>> &envelopes) {
    // vector<env> envs;
    // envs.reserve(envelopes.size());
    // for (auto e : envelopes) {
    //   envs.emplace_back(e[0], e[1]);
    // }
    sort(envelopes.begin(), envelopes.end(), cmp());

    int n = envelopes.size();
    vector<int> dp(n, 1);

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (envelopes[j][1] < envelopes[i][1]) {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }
    }

    return *max_element(dp.begin(), dp.end());
  }
};

int main() {
  vector<vector<int>> envelopes = {{17, 15}, {17, 18}, {2, 8}, {7, 2},
                                   {17, 2},  {17, 8},  {6, 15}};
  Solution so;
  cout << so.maxEnvelopes(envelopes);
}