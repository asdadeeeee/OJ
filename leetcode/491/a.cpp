#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
  inline void visit(vector<int> &nums, int curidx) {
    if (cur.size() > 1) {
      ans.emplace_back(cur);
    }
    int n = nums.size();
    vector<int> next;
    for (int i = curidx; i < n; i++) {
      if (i > curidx && nums[i] == nums[i - 1]) {
        continue;
      }
      if (cur.empty()) {
        bool repe = false;
        for (int j = 0; j < i; j++) {
          if (nums[j] == nums[i]) {
            repe = true;
            break;
          }
        }
        if (repe) {
          continue;
        }
      }

      if (cur.empty() || nums[i] >= cur.back()) {
        if (find(next.begin(), next.end(), nums[i]) != next.end()) {
          continue;
        }
        next.push_back(nums[i]);
        cur.push_back(nums[i]);
        visit(nums, i + 1);
        cur.pop_back();
      }
    }
  }
  vector<vector<int>> findSubsequences(vector<int> &nums) {
    visit(nums, 0);
    return ans;
  }
  vector<int> cur;
  vector<vector<int>> ans;
};

int main() {
  Solution so;
  vector<int> nums = {0, 0, 1, 1, 2, 2, 1, 1};
  so.findSubsequences(nums);
}