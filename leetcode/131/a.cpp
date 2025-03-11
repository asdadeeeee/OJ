#include <string>
#include <vector>
using namespace std;
class Solution {
public:
  bool rev(string &s) {

    int n = s.length();
    int left = 0;
    int right = n - 1;
    while (left < right) {
      if (s[left] != s[right]) {
        return false;
      }
      left++;
      right--;
    }
    return true;
  }

  void visit(string s) {
    if (s.empty()) {
      ans.emplace_back(cur);
    }
    int n = s.length();
    for (int i = 1; i <= n; i++) {
      string left = s.substr(0, i);
      string right;
      if (i < n) {
        right = s.substr(i, n - i);
      }
      if (rev(left)) {
        cur.emplace_back(left);
        visit(right);
        cur.pop_back();
      }
    }
  };
  vector<vector<string>> partition(string s) {
    visit(s);
    return ans;
  }

  vector<vector<string>> ans;
  vector<string> cur;
};
