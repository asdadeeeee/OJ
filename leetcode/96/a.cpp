#include <vector>
using namespace std;
class Solution {
public:
  int numTrees(int n) {
    if (n == 1) {
      return 1;
    }
    if (n == 2) {
      return 2;
    }
    if (n == 3) {
      return 5;
    }
    vector<int> t(n + 1, 0);
    t[0] = 1; 
    t[1] = 1;
    t[2] = 2;
    t[3] = 5;
    for (int i = 4; i <= n; i++) {
      for (int j = 1; j <= i; j++) {
        int left = j - 1;
        int right = i - j;
        t[i] += t[left] * t[right];
      }
    }
    return t[n];
  }
};