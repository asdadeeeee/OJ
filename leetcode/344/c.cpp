#include <string>
#include <vector>
using namespace std;
class Solution {
public:
  void reverseString(vector<char> &s) {
    int n = s.size();
    int left = 0;
    int right = n - 1;
    while (left < right) {
      swap(s[left], s[right]);
      left++;
      right--;
    }
  }
};