#include <string>
#include <vector>
using namespace std;
class Solution {
public:
  int strStr(string haystack, string needle) {
    int n = haystack.size();
    int length = needle.size();
    vector<int> next(length, 0);
    int j = 0;
    next[j] = 0;
    for (int i = 1; i < length; i++) {
      while (j > 0 && needle[j] != needle[i]) {
        j = next[j - 1];
      }
      if (needle[i] == needle[j]) {
        j++;
      }
      next[i] = j;
    }
    j = 0;
    for (int i = 0; i < n; i++) {
      while (j > 0 && haystack[i] != needle[j]) {
        j = next[j - 1];
      }
      if (haystack[i] == needle[j]) {
        j++;
      }
      if (j == length) {
        return i - length + 1;
      }
    }
    return -1;
  }
};