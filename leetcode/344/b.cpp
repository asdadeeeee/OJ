#include <string>
#include <vector>
using namespace std;
class Solution {
public:
  inline void reverse(vector<char> &s, int cur) {
    int n = s.size();
    if (cur == n - 1) {
      return;
    }
    reverse(s, cur + 1);
    char temp = s[cur];
    for (int i = cur; i < n - 1; i++) {
      s[i] = s[i + 1];
    }
    s[n - 1] = temp;
  }
  void reverseString(vector<char> &s) { reverse(s, 0); }
};