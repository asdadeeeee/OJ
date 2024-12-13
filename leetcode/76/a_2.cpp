#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
  std::unordered_map<char, int> ori, temp;
  bool contain() {
    for (auto const &pair : ori) {
      if (temp[pair.first] < pair.second) {
        return false;
      }
    }
    return true;
  }
  string minWindow(string s, string t) {
    for (const auto &c : t) {
      ori[c]++;
    }
    int ansL = -1;
    int ansK = 0x3f3f3f3f;
    int left = 0;
    int right = -1;
    while (right < int(s.length())) {
      if (ori.find(s[++right]) != ori.end()) {
        temp[s[right]]++;
      }
      while (contain() && left <= right) {
        int k = right - left + 1;
        if (k < ansK) {
          ansL = left;
          ansK = k;
        }
        if (ori.find(s[left]) != ori.end()) {
          temp[s[left]]--;
        }
        left++;
      }
    }
    return ansL == -1 ? string() : s.substr(ansL, ansK);
  }
};