#include <set>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
public:
  vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
    unordered_set<int> ans_set;

    unordered_set<int> s1(nums1.begin(), nums1.end());
    unordered_set<int> s2(nums2.begin(), nums2.end());
    for (auto n : s2) {
      if (s1.find(n) != s1.end()) {
        ans_set.insert(n);
      }
    }
    vector<int> ans(ans_set.begin(), ans_set.end());
    return ans;
  }
};