#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
  void visit(vector<int> &nums, int curidx) {
    ans.emplace_back(cur);
    int n = nums.size();
    for (int i = curidx; i < n; i++) {
      if (i > curidx && nums[i] == nums[i - 1]) {
        continue;
      }
      cur.push_back(nums[i]);
      visit(nums, i + 1);
      cur.pop_back();
    }
  }
  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    visit(nums, 0);
    return ans;
  }
  vector<vector<int>> ans;
  vector<int> cur;
};