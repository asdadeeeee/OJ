#include <algorithm>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
    vector<int> ans;
    unordered_map<int, int> m1;
    unordered_map<int, int> m2;
    for (int c : nums1) {
      m1[c]++;
    }
    for (int c : nums2) {
      m2[c]++;
    }
    for (auto it : m2) {
      int t = min(it.second, m1[it.first]);
      while (t > 0) {
        ans.emplace_back(it.first);
        t--;
      }
    }
    return ans;
  }
};