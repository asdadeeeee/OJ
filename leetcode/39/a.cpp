#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<int> temp;
    vector<vector<int>> ans;
    int temp_sum = 0;
    peek(candidates, target, temp, temp_sum, ans, 0);
    return ans;
  }
  void peek(vector<int> &candidates, int target, vector<int> &temp,
            int &temp_sum, vector<vector<int>> &ans, int cur) {
    if (temp_sum == target) {
      ans.emplace_back(temp);
      return;
    }
    if (temp_sum > target) {
      return;
    }

    for (int i = cur; i < candidates.size(); i++) {
      if (temp_sum + candidates[i] <= target) {
        temp_sum += candidates[i];
        temp.emplace_back(candidates[i]);
        peek(candidates, target, temp, temp_sum, ans, i);
        temp_sum -= candidates[i];
        temp.pop_back();
      } else {
        return;
      }
    }
  }
};