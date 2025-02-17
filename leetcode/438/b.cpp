#include <cstring>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  unordered_map<char, int> target, cur;
  bool match() {
    for (auto it : target) {
      if (cur[it.first] != it.second) {
        return false;
      }
    }
    return true;
  }
  vector<int> findAnagrams(string s, string p) {
    vector<int> ans;
    for (char c : p) {
      target[c]++;
    }
    int pl = p.length();
    int right = s.length();
    int left_ptr = 0;
    int right_ptr = 0 + pl - 1;
    for (int i = left_ptr; i <= right_ptr; i++) {
      cur[s[i]]++;
    }
    while (right_ptr < right) {
      if (match()) {
        ans.emplace_back(left_ptr);
      }
      right_ptr++;
      cur[s[right_ptr]]++;
      cur[s[left_ptr]]--;
      if (cur[s[left_ptr]] == 0) {
        cur.erase(s[left_ptr]);
      }
      left_ptr++;
    }
    return ans;
  }
};
