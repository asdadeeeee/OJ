#include <vector>
using namespace std;
class Solution {
public:
  bool lemonadeChange(vector<int> &bills) {
    vector<int> c(21, 0);
    for (auto b : bills) {
      switch (b) {
      case 5: {
        c[5]++;
        break;
      }
      case 10: {
        if (c[5] <= 0) {
          return false;
        }
        c[10]++;
        c[5]--;
        break;
      }
      case 20: {
        if (c[10] > 0) {
          c[10]--;
          if (c[5] <= 0) {
            return false;
          }
          c[5]--;
        } else {
          if (c[5] < 3) {
            return false;
          }
          c[5] = c[5] - 3;
        }
        c[20]++;
      }
      }
    }
    return true;
  }
};