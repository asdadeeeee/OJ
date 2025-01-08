#include <algorithm>
#include <cstring>
#include <ios>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  int minimumDeleteSum(string s1, string s2) {
    int l1 = s1.length();
    int l2 = s2.length();
    int p[l2 + 1];
    p[0] = 0;
    for (int i = 1; i <= l2; i++) {
      p[i] = p[i - 1] + s2[i - 1];
    }
    int leftup = 0;
    for (int i = 1; i <= l1; i++) {
      leftup = p[0];
      p[0] = p[0] + s1[i - 1];
      for (int j = 1; j <= l2; j++) {
        int temp = p[j];
        if (s1[i - 1] == s2[j - 1]) {
          p[j] = leftup;
        } else {
          p[j] = min(p[j] + s1[i - 1], p[j - 1] + s2[j - 1]);
        }
        leftup = temp;
      }
    }
    return p[l2];
  }
};

int main() {
  Solution so;
  cout << so.minimumDeleteSum("asd", "sd");
}