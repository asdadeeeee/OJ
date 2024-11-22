#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <math.h>
#include <vector>
using namespace std;
class Solution {
public:
  int nonSpecialCount(int l, int r) {
    int num = r - l + 1;
    int n = sqrt(r);
    vector<int> isPrime(n + 1, 1);
    for (int i = 2; i <= n; i++) {
      if (isPrime[i]) {
        if (i * i >= l && i * i <= r) {
          num--;
        }
        for (int j = i * i; j <= n; j += i) {
          isPrime[j] = 0;
        }
      }
    }
    return num;
  }
};
int main() {
  int L, R;
  std::cin >> L >> R;
  Solution sol;
  int t = sol.nonSpecialCount(L, R);
  std::cout << t;
}
