
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
      if (!take[i]) {
        cur.push_back(nums[i]);
        take[i] = true;
        visit(nums);
        cur.pop_back();
        take[i] = false;
      }
    }
  }
  vector<vector<int>> permute(vector<int> &nums) {
    take.resize(nums.size(), false);
    visit(nums);
    return ans;
  }
  vector<vector<int>> ans;
  vector<int> cur;
  vector<bool> take;
};