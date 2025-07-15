#include <cstring>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> M;
    int n = s.length();
    if (n == 1 || n == 0) {
      return n;
    }
    int leftptr = 0;
    M[s[leftptr]]++;
    int rightptr = 1;
    int ans = 0;
    while (leftptr <= rightptr && rightptr < n) {
      while (M[s[rightptr]] != 0) {
        M[s[leftptr]]--;
        leftptr++;
      }
      M[s[rightptr]]++;
      ans = max(ans, rightptr - leftptr + 1);
      rightptr++;
    }
    return ans;
  }
};