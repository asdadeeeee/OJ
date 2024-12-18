#include <stack>
#include <vector>

using namespace std;
class Solution {

public:
  vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
    vector<int> res(10010);
    int size = nums2.size();
    for (int i = size - 1; i >= 0; i--) {
      int n = nums2[i];
      while (!a.empty() && a.top() <= n) {
        a.pop();
      }
      res[n] = a.empty() ? -1 : a.top();
      a.push(n);
    }

    vector<int> ans;
    for (auto n : nums1) {
      ans.push_back(res[n]);
    }
    return ans;
  }
  std::stack<int> a;
};
