#include <cstring>
#include <iostream>
#include <string>

using namespace std;
class Solution {
public:
  string getpal(string &s, int left, int right) {
    int length = 0;
    int resL;
    while (left >= 0 && right <= s.length() - 1 && s[left] == s[right]) {
      length = right - left + 1;
      resL = left;
      left--;
      right++;
    }
    if (length > 0) {
      return s.substr(resL, length);
    }
    return "";
  }
  string longestPalindrome(string s) {
    int k = 0;
    string ans;
    for (int i = 0; i < s.length(); i++) {
      string temp1 = getpal(s, i, i);
      string temp2 = getpal(s, i, i + 1);
      auto temp = temp1.length() > temp2.length() ? temp1 : temp2;
      if (temp.length() > k) {
        k = temp.length();
        ans = temp;
      }
    }
    return ans;
  }
};
