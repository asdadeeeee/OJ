#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
  unordered_map<int, int> visit;
  inline int su(int n) {
    int res = 0;
    while (n >= 10) {
      int t = n % 10;
      res += t * t;
      n = n / 10;
    }
    res += n * n;
    return res;
  }
  bool isHappy(int n) {
    while (visit[n] != 1) {
      visit[n] = 1;
      int next = su(n);
      if (next == 1) {
        return true;
      }
      n = next;
    }
    return false;
  }
};

int main() {
  Solution so;
  so.isHappy(19);
}