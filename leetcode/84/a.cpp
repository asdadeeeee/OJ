#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
  int largestRectangleArea(vector<int> &heights) {
    stack<int> s;
    heights.insert(heights.begin(), 0); // 数组头部加入元素0
    heights.push_back(0);               // 数组尾部加入元素0
    int n = heights.size();
    int ans = 0;
    s.push(0);
    for (int i = 1; i < n; i++) {
      int e = heights[i];
      while (!s.empty() && heights[s.top()] >= e) {
        int height = heights[s.top()];
        s.pop();
        if (!s.empty()) {
          int leftidx = s.top();
          int width = i - leftidx - 1;
          ans = max(ans, width * height);
        }
      }
      s.push(i);
    }
    return ans;
  }
};

int main() {
  vector<int> heights = {2, 1, 5, 6, 2, 3};
  Solution so;
  so.largestRectangleArea(heights);
}