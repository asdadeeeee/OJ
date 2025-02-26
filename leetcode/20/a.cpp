#include <stack>
#include <string>
using namespace std;
class Solution {
public:
  bool isValid(string s) {
    for (char c : s) {
      switch (c) {
      case '(':
      case '{':
      case '[': {
        A.push(c);
        break;
      }
      case ')': {
        if (A.empty()) {
          return false;
        }
        char t = A.top();
        if (t == '(') {
          A.pop();
        } else {
          return false;
        }
        break;
      }
      case '}': {
        if (A.empty()) {
          return false;
        }
        char t = A.top();
        if (t == '{') {
          A.pop();
        } else {
          return false;
        }
        break;
      }
      case ']': {
        if (A.empty()) {
          return false;
        }
        char t = A.top();
        if (t == '[') {
          A.pop();
        } else {
          return false;
        }
        break;
      }
      }
    }
    if (A.empty()) {
      return true;
    }
    return false;
  }

  stack<char> A;
};