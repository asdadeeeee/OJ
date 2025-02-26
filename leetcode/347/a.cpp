#include <map>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;
struct cmp {
  bool operator()(const pair<int, int> &p1, const pair<int, int> &p2) {
    return p1.second < p2.second;
  }
};

class Solution {

public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    unordered_map<int, int> m;
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
    for (int n : nums) {
      m[n]++;
    }
    for (auto p : m) {
      q.push({p.first, p.second});
    }
    vector<int> ans;
    while (k--) {
      ans.emplace_back(q.top().first);
      q.pop();
    }
    return ans;
  }
  
};