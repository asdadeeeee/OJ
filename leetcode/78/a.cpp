#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> subsets(vector<int> &nums) {
    peek(nums, 0);
    return ans;
  }

  void peek(vector<int> &nums, int cur_idx) {
    ans.emplace_back(temp);
    for (int i = cur_idx; i < nums.size(); i++) {
      temp.push_back(nums[i]);
      peek(nums, i + 1);
      temp.pop_back();
    }
  }

  vector<int> temp;
  vector<vector<int>> ans;
};

int main() {
  vector<int> nums = {1, 2, 3};
  Solution so;
  so.subsets(nums);
}