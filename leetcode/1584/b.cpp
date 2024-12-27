#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class Solution {
public:
  int minCostConnectPoints(vector<vector<int>> &points) { return prim(points); }

  int dis(vector<int> &p, vector<int> &q) {
    return abs(p[0] - q[0]) + abs(p[1] - q[1]);
  }
  int prim(vector<vector<int>> &points) {
    vector<bool> state;
    vector<int> dist;
    vector<int> pre;
    int inf = 0x3f3f3f3f;
    int size = points.size();
    state.resize(size, false);
    dist.resize(size, inf);
    pre.resize(size, -1);
    state[0] = true;
    dist[0] = 0;
    int res = 0;
    for (int i = 1; i < size; i++) {
      dist[i] = dis(points[0], points[i]);
    }
    for (int i = 1; i < size; i++) {
      int t = -1;
      for (int k = 1; k < size; k++) {
        if (!state[k] && (t == -1 || dist[k] < dist[t])) {
          t = k;
        }
      }
      if (dist[t] == inf) {
        return -1;
      }
      state[t] = true;
      res += dist[t];
      for (int k = 1; k < size; k++) {
        int new_dis = dis(points[t], points[k]);
        if (!state[k] && new_dis < dist[k]) {
          dist[k] = new_dis;
          pre[k] = t;
        }
      }
    }
    return res;
  }
};

int main() {
  vector<vector<int>> points{{0, 0}, {2, 2}};
  Solution so;
  cout << so.minCostConnectPoints(points);
}