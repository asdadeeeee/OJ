#include <map>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
  unordered_map<char, int> target, cur;
  bool contain() {
    for (auto it : target) {
      if (cur[it.first] < it.second) {
        return false;
      }
    }
    return true;
  }
  string minWindow(string s, string t) {
    int ansL = -1;
    int ansR = -1;
    int ans_length = 0x3f3f3f3f;
    int n1 = s.size();
    for (char c : t) {
      target[c]++;
    }
    int left_ptr = 0;
    int right_ptr = 0;
    for (right_ptr = 0; right_ptr < n1; right_ptr++) {
      if (target.find(s[right_ptr]) != target.end()) {
        cur[s[right_ptr]]++;
      }
      while (contain() && left_ptr <= right_ptr) {
        if (right_ptr - left_ptr + 1 < ans_length) {
          ans_length = right_ptr - left_ptr + 1;
          ansL = left_ptr;
          ansR = right_ptr;
        }
        if (target.find(s[left_ptr]) != target.end()) {
          cur[s[left_ptr]]--;
          if (cur[s[left_ptr]] == 0) {
            cur.erase(s[left_ptr]);
          }
        }
        left_ptr++;
      }
    }
    if (ansL == -1) {
      return "";
    }
    return s.substr(ansL, ans_length);
  }
};