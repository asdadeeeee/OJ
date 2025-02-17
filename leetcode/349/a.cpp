#include <set>
#include <vector>
using namespace std;
class Solution {
public:
  vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
    vector<int> ans;
    set<int> s1;
    set<int> s2;
    for (int n : nums1) {
      s1.insert(n);
    }
    for (int n : nums2) {
      s2.insert(n);
    }
    auto it1 = s1.begin();
    auto it2 = s2.begin();
    while (it1 != s1.end() && it2 != s2.end()) {
      if (*it1 == *it2) {
        ans.emplace_back(*it1);
        it1++;
        it2++;
      } else if (*it1 < *it2) {
        it1++;
      } else if (*it2 < *it1) {
        it2++;
      }
    }
    return ans;
  }
};
int main() {
  vector<int> nums1 = {1, 2, 2, 1};
  vector<int> nums2 = {2, 2};
  Solution so;
  so.intersection(nums1, nums2);
}