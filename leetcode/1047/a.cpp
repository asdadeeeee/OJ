#include <stack>
#include <string>
using namespace std;
class Solution {
public:
  string removeDuplicates(string s) {
    for (char c : s) {
      if (!A.empty() && A.top() == c) {
        A.pop();
      } else {
        A.push(c);
      }
    }
    string ans;
    while (!A.empty()) {
      char c = A.top();
      ans = c + ans;
      A.pop();
    }
    return ans;
  }
  stack<char> A;
};