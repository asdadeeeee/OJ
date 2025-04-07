#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
  int trap(vector<int> &height) {
    int ans = 0;
    int n = height.size();
    stack<int> s;
    for (int i = 0; i < n; i++) {
      int e = height[i];
      while (!s.empty() && height[s.top()] <= e) {
        if (height[s.top()] == e) {
          s.pop();
          continue;
        } else {
          int lowidx = s.top();
          int low = height[lowidx];
          s.pop();
          if (s.empty()) {
            break;
          }
          int leftidx = s.top();
          int left = height[leftidx];
          int right = e;
          int width = i - leftidx - 1;
          ans += width * (min(left, right) - low);
        }
      }
      s.push(i);
    }
    return ans;
  }
};