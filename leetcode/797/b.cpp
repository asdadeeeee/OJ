#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
    n = graph.size() - 1;
    track.emplace_back(0);
    dfs(graph, 0);
    return ans;
  }

  void dfs(vector<vector<int>> &graph, int cur) {
    if (cur == n) {
      ans.emplace_back(track);
      return;
    }
    for (auto next : graph[cur]) {
      track.emplace_back(next);
      dfs(graph, next);
      track.pop_back();
    }
  }

  int n;
  vector<int> track;
  vector<vector<int>> ans;
};