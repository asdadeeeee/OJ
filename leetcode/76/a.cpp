#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
  unordered_map<char, int> ori, cnt;
  bool check() {
    for (const auto &pair : ori) {
      if (cnt[pair.first] < pair.second) {
        return false;
      }
    }
    return true;
  }
  string minWindow(string s, string t) {
    int ansL = -1;
    int ansK = 0x3f3f3f3f;
    for (const auto &c : t) {
      ori[c]++;
    }
    int left = 0;
    int right = -1;
    while (right < int(s.length())) {
      if (ori.find(s[++right]) != ori.end()) { // trick
        cnt[s[right]]++;
      }
      while (check() && left <= right) {
        int k = right - left + 1;
        if (k < ansK) {
          ansK = k;
          ansL = left;
        }
        if (ori.find(s[left]) != ori.end()) {
          cnt[s[left]]--;
        }
        left++;
      }
    }
    return ansL == -1 ? string() : s.substr(ansL, ansK);
  }
};

int main() {
  string s = "ADOBECODEBANC";
  string t = "ABC";
  Solution so;
  auto res = so.minWindow(s, t);
  cout << res;
}