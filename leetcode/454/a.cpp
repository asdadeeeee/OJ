#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
  int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3,
                   vector<int> &nums4) {
    unordered_map<int, int> sumab;
    int ans = 0;
    for (auto a : nums1) {
      for (auto b : nums2) {
        sumab[a + b]++;
      }
    }
    for (auto c : nums3) {
      for (auto d : nums4) {
        ans += sumab[-c - d];
      }
    }
    return ans;
  }
};