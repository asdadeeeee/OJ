#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
    travel(graph, 0);
    return ans;
  }

  void travel(vector<vector<int>> &graph, int node) {
    track.emplace_back(node);
    if (node == graph.size() - 1) {
      ans.emplace_back(track);
    }
    for (auto n : graph[node]) {
      travel(graph, n);
    }
    track.pop_back();
  }

  vector<int> track;
  vector<vector<int>> ans;
};