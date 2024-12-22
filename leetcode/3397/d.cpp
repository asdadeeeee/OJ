#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;
class Solution {
public:
  int maxDistinctElements(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end());
    int pre = -0x3f3f3f3f;
    int count = 0;
    for (auto n : nums) {
      int t = min(max(pre + 1, n - k), n + k);
      if (t > pre) {
        pre = t;
        count++;
      }
    }
    return count;
  }
};