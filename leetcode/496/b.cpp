#include <stack>
#include <vector>

using namespace std;
class Solution {
public:
  vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
    stack<int> s;

    vector<int> res(10001, 0);
    int n = nums2.size();
    for (int i = n - 1; i >= 0; i--) {
      int e = nums2[i];
      while (!s.empty() && s.top() < e) {
        s.pop();
      }
      res[e] = s.empty() ? -1 : s.top();
      s.push(e);
    }
    vector<int> ans;
    for (auto num : nums1) {
      ans.emplace_back(res[num]);
    }
    return ans;
  }
};