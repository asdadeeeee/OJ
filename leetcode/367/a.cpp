#include <algorithm>
using namespace std;

class Solution {
public:
  bool isPerfectSquare(int num) {
    int left = 1;
    int right = min(num, 46340);
    while (left <= right) {
      int mid = left + (right - left) / 2;
      int temp = mid * mid;
      if (temp == num) {
        return true;
      } else if (temp > num) {
        right = mid - 1;
      } else if (temp < num) {
        left = mid + 1;
      }
    }
    return false;
  }
};