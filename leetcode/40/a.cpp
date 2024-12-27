#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<int> temp;
    vector<vector<int>> ans;
    int cnt = 0;
    dfs(temp, ans, candidates, 0, target, cnt);
    return ans;
  }

  void dfs(vector<int> &temp, vector<vector<int>> &ans, vector<int> &candidates,
           int cur, int target, int &cnt) {
    if (cnt == target) {
      ans.emplace_back(temp);
    }
    for (int i = cur; i < candidates.size(); i++) {
      if (i > cur && candidates[i] == candidates[i - 1]) {
        continue;
      }
      if (cnt + candidates[i] > target) {
        return;
      }
      cnt += candidates[i];
      temp.emplace_back(candidates[i]);
      dfs(temp, ans, candidates, i + 1, target, cnt);
      cnt -= candidates[i];
      temp.pop_back();
    }
  }
};
