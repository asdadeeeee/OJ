
#include <vector>
using namespace std;
class Solution {
public:
  vector<vector<int>> permute(vector<int> &nums) {
    vector<bool> if_take;
    if_take.resize(nums.size());
    vector<int> takes;
    dfs(nums, takes, if_take);
    return ans_;
  }

  void dfs(vector<int> &nums, vector<int> &takes, vector<bool> if_take) {
    if (takes.size() == nums.size()) {
      ans_.emplace_back(takes);
      return;
    }

    for (int i = 0; i < nums.size(); i++) {

      if (!if_take.at(i)) {
        takes.emplace_back(nums.at(i));
        if_take.at(i) = true;
        dfs(nums, takes, if_take);
        takes.pop_back();
        if_take.at(i) = false;
      }
    }
  }

  vector<bool> if_take;
  vector<int> takes;
  vector<vector<int>> ans_;
};