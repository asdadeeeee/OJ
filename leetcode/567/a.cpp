#include <cstring>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
  unordered_map<char, int> ori, temp;
  bool contain() {
    for (auto const &pair : ori) {
      if (temp[pair.first] < pair.second) {
        return false;
      }
    }
    return true;
  }
  bool checkInclusion(string s1, string s2) {
    for (auto c : s1) {
      ori[c]++;
    }
    int left = 0;
    int right = left + s1.length() - 1;
    auto temp_str = s2.substr(left, right - left + 1);

    for (auto c : temp_str) {
      temp[c]++;
    }
    bool found = false;
    if (contain()) {
      return true;
    }
    while (right < int(s2.length() - 1)) {
      right++;
      if (ori.find(s2[right]) != ori.end()) {
        temp[s2[right]]++;
      }
      if (ori.find(s2[left]) != ori.end()) {
        temp[s2[left]]--;
      }
      left++;
      found = contain();
      if (found) {
        return true;
      }
    }
    return false;
  }
};