#include <vector>
using namespace std;
class Solution {
public:
  void visit(vector<int> &nums, int curidx) {
    ans.emplace_back(cur);
    for (int i = curidx; i < nums.size(); i++) {
      cur.push_back(nums[i]);
      visit(nums, i + 1);
      cur.pop_back();
    }
  }
  vector<vector<int>> subsets(vector<int> &nums) {
    visit(nums, 0);
    return ans;
  }
  vector<vector<int>> ans;
  vector<int> cur;
};