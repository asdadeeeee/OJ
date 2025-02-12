#include <algorithm>
using namespace std;
class Solution {
public:
  int mySqrt(int x) {
    int left = 1;
    int right = min(x, 46340);
    int mid = 0;
    while (left <= right) {
      mid = left + (right - left) / 2;
      int temp = mid * mid;
      if (temp == x) {
        return mid;
      } else if (temp > x) {
        right = mid - 1;
      } else if (temp < x) {
        left = mid + 1;
      }
    }
    return right;
  }
};