#include <cstring>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
  bool repeat() {
    for (auto const &pair : chars) {
      if (pair.second > 1) {
        return true;
      }
    }
    return false;
  }
  int lengthOfLongestSubstring(string s) {
    int size = s.length();
    int left = 0;
    int right = 0;
    int ans = 0;

    while (right < size) {
      char c = s[right];
      chars[c]++;
      right++;
      while (chars[c] > 1) {
        chars[s[left++]]--;
      }
      int k = right - left;
      ans = max(ans, k);
    }
    return ans;
  }

  unordered_map<char, int> chars;
};