#include <cmath>
#include <iostream>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
public:
  int getNum() {
    int res = 0;
    for (auto p : count) {
      if (p.second > 0) {
        res++;
      }
    }
    return res;
  }
  void dfs(vector<int> &nums, int ptr, int k) {
    for (int i = -k; i <= k; i++) {
      int t = nums[ptr] + i;
      count[t]++;
      if (ptr == nums.size() - 1) {
        ans = max(getNum(), ans);
      } else {
        dfs(nums, ptr + 1, k);
      }
      count[t]--;
    }
  }
  int maxDistinctElements(vector<int> &nums, int k) {
    dfs(nums, 0, k);
    return ans;
  }
  unordered_map<int, int> count;
  int ans = -1;
};

int main() {
  vector<int> nums{65, 64, 65, 61};
  Solution so;
  cout << so.maxDistinctElements(nums, 58);
}