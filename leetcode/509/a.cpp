class Solution {
public:
  int fib(int n) {
    if (n == 0 || n == 1) {
      return n;
    }
    int dpi = 0;
    int dp_i_2 = 0;
    int dp_i_1 = 1;
    for (int i = 2; i <= n; i++) {
      dpi = dp_i_2 + dp_i_1;
      dp_i_2 = dp_i_1;
      dp_i_1 = dpi;
    }
    return dpi;
  }
};