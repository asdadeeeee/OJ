#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class cmp {
public:
  bool operator()(const int &a, const int &b) { return a >= b; }
};
class Solution {
public:
  bool canPartitionKSubsets(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end(), cmp());
    int sum = 0;
    for (auto t : nums) {
      sum += t;
    }
    if (sum % k != 0) {
      return false;
    }
    int target = sum / k;
    int used = 0;
    vector<int> bucket(k, 0);
    unordered_map<int, bool> memo;
    return peek(nums, used, target, bucket, 0, 0, k, memo);
  }

  inline bool peek(vector<int> &nums, int &used, int target,
                   vector<int> &bucket, int temp, int cur, int k,
                   unordered_map<int, bool> &memo) {
    if (temp == k) {
      return true;
    }
    if (bucket[temp] == target) {
      bool p = peek(nums, used, target, bucket, temp + 1, 0, k, memo);
      memo.insert({used, p});
      return p;
    }
    auto it = memo.find(used);
    if (it != memo.end()) {
      return it->second;
    }
    for (int i = cur; i < nums.size(); i++) {
      if ((used >> i & 1) || bucket[temp] + nums[i] > target) {
        continue;
      }
      used |= 1 << i;
      bucket[temp] += nums[i];
      if (peek(nums, used, target, bucket, temp, i + 1, k, memo)) {
        return true;
      }
      used ^= 1 << i;
      bucket[temp] -= nums[i];
    }
    return false;
  }
};