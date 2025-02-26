#include <cstdlib>
#include <stack>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
  inline int calc(string s, int left, int right) {
    if (s == "+") {
      return left + right;
    } else if (s == "*") {
      return left * right;
    } else if (s == "-") {
      return left - right;
    } else if (s == "/") {
      return left / right;
    }
    return 0x3f3f3f3f;
  }
  int evalRPN(vector<string> &tokens) {
    stack<int> v;
    for (auto s : tokens) {
      if (s == "+" || s == "-" || s == "*" || s == "/") {
        int right = v.top();
        v.pop();
        int left = v.top();
        v.pop();
        int res = calc(s, left, right);
        v.push(res);
      } else {
        v.push(atoi(s.c_str()));
      }
    }
    return v.top();
  }
};
