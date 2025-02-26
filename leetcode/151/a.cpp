#include <string>
#include <tuple>
using namespace std;
class Solution {
public:
  inline string reverse(string &s, int left, int right) {
    int begin = left;
    int length = right - left + 1;
    while (left < right) {
      swap(s[left], s[right]);
      left++;
      right--;
    }
    return s.substr(begin, length);
  }
  inline void rev(string &s) {
    int n = s.size();
    int left = 0;
    int right = n - 1;
    while (left < right) {
      swap(s[left], s[right]);
      left++;
      right--;
    }
  }
  string reverseWords(string s) {
    int n = s.size();
    string ans;
    int left = 0;
    rev(s);
    while (left <= n - 1) {
      if (s[left] == ' ') {
        left++;
        continue;
      }
      int right = left;
      while (right <= n - 1 && s[right] != ' ') {
        right++;
      }
      ans += reverse(s, left, right - 1) + ' ';
      left = right;
    }
    ans = ans.substr(0, ans.size() - 1);
    return ans;
  }
};