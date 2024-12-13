#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  
  void print(vector<char> &s) {
    for (const auto c : s) {
      cout << c;
    }
  }
  void reverseString(vector<char> &s) {
    int size = s.size() - 1;
    int left = 0;
    int right = size;
    while (left < right) {
      swap(s[left], s[right]);
      left++;
      right--;
    }
  }
};

int main() {
  vector<char> s = {'h', 'e', 'l', 'v', 'c'};
  Solution sol;
  sol.reverseString(s);
  sol.print(s);
}