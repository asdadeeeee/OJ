#include <vector>
using namespace std;
class Solution {
public:
  int integerBreak(int n) {
    vector<int> c(n + 1, 0);
    c[0] = 0;
    c[1] = 0;
    c[2] = 1;
    for (int i = 3; i <= n; i++) {
      for (int j = 1; j <= i - 1; j++) {
        c[i] = max(c[i], max(j * (i - j), j * c[i - j]));
      }
    }
    return c[n];
  }
};