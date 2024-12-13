#include <cstring>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
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

  vector<int> findAnagrams(string s, string p) {
    std::vector<int> res;
    for (const auto c : p) {
      ori[c]++;
    }
    int size = p.length();
    int left = 0;
    int right = left + size - 1;
    auto temp_str = s.substr(left, size);
    for (const auto c : temp_str) {
      if (ori.find(c) != ori.end()) {
        temp[c]++;
      }
    }

    while (right < s.length()) {
      if (contain()) {
        res.emplace_back(left);
      }
      right++;
      if (ori.find(s[right]) != ori.end()) {
        temp[s[right]]++;
      }

      if (ori.find(s[left]) != ori.end()) {
        temp[s[left]]--;
      }
      left++;
    };
    return res;
  }
};