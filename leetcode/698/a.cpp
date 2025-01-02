#include <algorithm>
#include <iostream>
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
    vector<bool> used(nums.size(), false);
    vector<int> bucket(k, 0);
    return peek(nums, target, bucket, 0);
  }

  bool peek(vector<int> &nums, int target, vector<int> &bucket, int cur) {
    if (cur == nums.size()) {
      for (auto b : bucket) {
        if (b != target) {
          return false;
        }
      }
      return true;
    }

    for (int i = 0; i < bucket.size(); i++) {
      if (bucket[i] + nums[cur] > target) {
        continue;
      }
      bucket[i] += nums[cur];
      if (peek(nums, target, bucket, cur + 1)) {
        return true;
      }
      bucket[i] -= nums[cur];
    }
    return false;
  };
};

int main() {
  vector<int> nums = {10, 1, 10, 9, 6, 1, 9, 5, 9, 10, 7, 8, 5, 2, 10, 8};
  Solution so;
  cout << so.canPartitionKSubsets(nums, 11);
}
