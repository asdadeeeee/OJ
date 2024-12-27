#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> permuteUnique(vector<int> &nums) {
    vector<int> temp;
    vector<vector<int>> ans;
    vector<bool> used(nums.size(), false);
    sort(nums.begin(), nums.end());
    dfs(temp, ans, used, nums);
    return ans;
  }

  void dfs(vector<int> &temp, vector<vector<int>> &ans, vector<bool> &used,
           vector<int> &nums) {
    if (temp.size() == nums.size()) {
      ans.emplace_back(temp);
      return;
    }
    for (int i = 0; i < nums.size(); i++) {
      if (used[i]) {
        continue;
      }
      if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) {
        continue;
      }
      temp.emplace_back(nums[i]);
      used[i] = true;
      dfs(temp, ans, used, nums);
      temp.pop_back();
      used[i] = false;
    }
  }
};