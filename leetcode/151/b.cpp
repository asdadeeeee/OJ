#include <string>
#include <tuple>
using namespace std;
class Solution {
public:
  inline void reverse(string &s, int left, int right) {
    while (left < right) {
      swap(s[left], s[right]);
      left++;
      right--;
    }
  }
  string reverseWords(string s) {
    int n = s.size();
    int left = 0;
    reverse(s, 0, n - 1);
    while (left <= s.size() - 1) {
      if (s[left] == ' ') {
        s.erase(left, 1);
        continue;
      }
      int right = left;
      while (right <= s.size() - 1 && s[right] != ' ') {
        right++;
      }
      reverse(s, left, right - 1);
      left = right + 1;
    }
    int i = s.size() - 1;
    while (i >= 0 && s[i] == ' ') {
      s.erase(i, 1);
      i--;
    }
    return s;
  }
};

int main() {
  Solution so;
  so.reverseWords("  hello world  ");
}