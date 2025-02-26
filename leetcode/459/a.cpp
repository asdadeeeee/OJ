#include <string>
#include <vector>
using namespace std;
class Solution {
public:
  bool repeatedSubstringPattern(string s) {
    int n = s.size();
    vector<int> next(n, 0);
    int j = 0;
    next[j] = 0;
    for (int i = 1; i < n; i++) {
      while (j > 0 && s[j] != s[i]) {
        j = next[j - 1];
      }
      if (s[i] == s[j]) {
        j++;
      }
      next[i] = j;
    }
    int length = next[n - 1];
    if (length != 0 && n % (n - length) == 0) {
      return true;
    }
    return false;
  }
};