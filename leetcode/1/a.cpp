#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> m;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      int b = target - nums[i];
      auto it = m.find(b);
      if (it != m.end()) {
        return {i, it->second};
      }
      m.emplace(nums[i], i);
    }
    return {0};
  }
};