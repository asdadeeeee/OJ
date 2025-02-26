#include <string>
#include <vector>
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
  string reverseStr(string s, int k) {
    string ans = s;
    int n = s.size();
    int left = 0;
    while (left < n - 1) {
      int tl = left;
      int tr = min(n - 1, tl + k - 1);
      reverse(ans, tl, tr);
      left += 2 * k;
    };
    return ans;
  }
};