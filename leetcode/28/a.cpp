#include <string>
using namespace std;
class Solution {
public:
  int strStr(string haystack, string needle) {
    int left = 0;
    int length = needle.length();
    int n = haystack.length();
    while (left <= n - length) {
      if (haystack.substr(left, length) == needle) {
        return left;
      }
      left++;
    }
    return -1;
  }
};