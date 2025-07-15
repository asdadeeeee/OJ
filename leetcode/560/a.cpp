#include <deque>
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
  int subarraySum(vector<int> &nums, int k) {
    int n = nums.size();
    unordered_map<int, int> map;
    int ans = 0;
    int temp_sum = 0;
    map[0] = 1;
    for (auto n : nums) {
      temp_sum += n;
      auto iter = map.find(temp_sum - k);
      if (iter != map.end()) {
        ans += iter->second;
      }
      map[temp_sum]++;
    }
    return ans;
  }
};
int main() {
  Solution so;
  vector<int> nums = {1, -1, 0};
  cout << so.subarraySum(nums, 0);
}