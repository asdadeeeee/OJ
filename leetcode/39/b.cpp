#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
  void visit(vector<int> &candidates, int &sum, int target, int &curidx) {
    if (sum == target) {
      ans.emplace_back(cur);
      return;
    }
    int n = candidates.size();
    for (int i = curidx; i < n; i++) {
      if (sum + candidates[i] > target) {
        return;
      } else {
        sum += candidates[i];
        cur.push_back(candidates[i]);
        visit(candidates, sum, target, i);
        sum -= candidates[i];
        cur.pop_back();
      }
    }
  };
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    sort(candidates.begin(), candidates.end());
    int sum = 0;
    int curidx = 0;
    visit(candidates, sum, target, curidx);
    return ans;
  }

private:
  vector<vector<int>> ans;
  vector<int> cur;
};