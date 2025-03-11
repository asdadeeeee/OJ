#include <map>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  void inline visit(int cur, string &digits) {
    if (temp.size() == digits.size()) {
      ans.emplace_back(temp);
      return;
    }
    for (int i = cur; i < digits.size(); i++) {
      for (int j = 0; j < phone[digits[i] - '0'].size(); j++) {
        temp.push_back(phone[digits[i] - '0'][j]);
        visit(i + 1, digits);
        temp.pop_back();
      }
    }
  }
  vector<string> letterCombinations(string digits) {
    if (digits.empty()) {
      return ans;
    }
    visit(0, digits);
    return ans;
  }

private:
  vector<string> ans;
  string temp;
  vector<string> phone = {"",    "",    "abc",  "def", "ghi",
                          "jkl", "mno", "pqrs", "tuv", "wxyz"};
};
