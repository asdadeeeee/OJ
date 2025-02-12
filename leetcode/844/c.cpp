#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
  string back(string str) {
    string res;
    for (auto c : str) {
      if (c != '#') {
        res.push_back(c);
      } else if (!res.empty()) {
        res.pop_back();
      }
    }
    return res;
  }
  bool backspaceCompare(string s, string t) { return back(s) == back(t); }
};