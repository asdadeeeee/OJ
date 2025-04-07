#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
struct node {
  int v;
  int pre;
};
class Solution {
public:
  vector<int> dailyTemperatures(vector<int> &temperatures) {
    stack<node> s;
    int n = temperatures.size();
    vector<int> ans(n, 0);
    for (int i = n - 1; i >= 0; i--) {
      int e = temperatures[i];
      int temp = 1;
      while (!s.empty() && s.top().v <= e) {
        temp += s.top().pre;
        s.pop();
      }
      temp = s.empty() ? 0 : temp;
      ans[i] = temp;
      node new_node{e, temp};
      s.push(new_node);
    }
    return ans;
  }
};