#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
  void visit(vector<int> &nums) {
    int n = nums.size();
    if (cur.size() == n) {
      ans.emplace_back(cur);
      return;
    }
    for (int i = 0; i < n; i++) {
      if (i > 0 && nums[i] == nums[i - 1] && !take[i - 1]) {
        continue;
      }
      if (!take[i]) {
        take[i] = true;
        cur.push_back(nums[i]);
        visit(nums);
        cur.pop_back();
        take[i] = false;
      }
    }
  }
  vector<vector<int>> permuteUnique(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    take.resize(nums.size(), false);
    visit(nums);
    return ans;
  }

  vector<vector<int>> ans;
  vector<int> cur;
  vector<bool> take;
};