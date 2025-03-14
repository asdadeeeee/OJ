#include <vector>
using namespace std;
class Solution {
public:
  int climbStairs(int n) {
    int c1 = 1;
    int c2 = 2;
    int c3 = 0;
    for (int i = 0; i <= n - 3; i++) {
      c3 = c1 + c2;
      c1 = c2;
      c2 = c3;
    }
    if (n == 1) {
      return 1;
    }
    if (n == 2) {
      return 2;
    }
    return c3;
  }
};