#include <algorithm>
#include <iostream>
#include <iterator>
#include <queue>
#include <vector>
using namespace std;
const int inf = 0x3f3f3f3f;

class Solution {
public:
  inline int dij(vector<vector<int>> &times, int n, int k) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
    vector<vector<pair<int, int>>> m(n + 1);
    for (const auto &e : times) {
      m[e[0]].emplace_back(e[1], e[2]);
    }
    vector<int> dist(n + 1, inf);
    dist[k] = 0;
    q.push({0, k});
    while (!q.empty()) {
      auto cur = q.top();
      q.pop();
      if (dist[cur.second] < cur.first) {
        continue;
      }
      for (const auto &e : m[cur.second]) {
        int d = dist[cur.second] + e.second;
        if (dist[e.first] > d) {
          dist[e.first] = d;
          q.push({dist[e.first], e.first});
        }
      }
    }
    int ans = *max_element(dist.begin() + 1, dist.end());
    return ans == inf ? -1 : ans;
  }
  int networkDelayTime(vector<vector<int>> &times, int n, int k) {
    return dij(times, n, k);
  }
};
int main() {
  vector<vector<int>> t = {{1, 2, 1}, {2, 1, 3}};
  Solution so;
  cout << so.networkDelayTime(t, 2, 2);
}