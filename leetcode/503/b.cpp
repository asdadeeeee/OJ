#include <stack>
#include <vector>

using namespace std;
class Solution {
public:
  vector<int> nextGreaterElements(vector<int> &nums) {
    int n = nums.size();
    vector<int> ans(n, 0);
    stack<int> s;
    for (int j = 0; j < 2; j++) {
      for (int i = n - 1; i >= 0; i--) {
        int e = nums[i];
        while (!s.empty() && s.top() <= e) {
          s.pop();
        }
        ans[i] = s.empty() ? -1 : s.top();
        s.push(e);
      }
    }
    return ans;
  }
};