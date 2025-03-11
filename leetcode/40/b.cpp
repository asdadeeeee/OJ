#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
  void visit(vector<int> &candidates, int target, int curidx, int &sum) {
    int n = candidates.size();
    if (sum == target) {
      ans.emplace_back(cur);
      return;
    }
    for (int i = curidx; i < n; i++) {
      if (i > curidx && candidates[i] == candidates[i - 1]) {
        continue;
      }
      if (sum + candidates[i] > target) {
        return;
      }
      sum += candidates[i];
      cur.push_back(candidates[i]);
      visit(candidates, target, i + 1, sum);
      sum -= candidates[i];
      cur.pop_back();
    }
  }
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {

    sort(candidates.begin(), candidates.end());
    int sum = 0;
    visit(candidates, target, 0, sum);
    return ans;
  }

private:
  vector<vector<int>> ans;
  vector<int> cur;
};