#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    vector<int> temp;
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    dfs(temp, ans, nums, 0);
    return ans;
  }

  void dfs(vector<int> &temp, vector<vector<int>> &ans, vector<int> &nums,
           int cur) {
    ans.emplace_back(temp);
    for (int i = cur; i < nums.size(); i++) {
      if (i > cur && nums[i] == nums[i - 1]) {
        continue;
      }
      temp.emplace_back(nums[i]);
      dfs(temp, ans, nums, i + 1);
      temp.pop_back();
    }
  }
};
