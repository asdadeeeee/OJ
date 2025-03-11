#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
  int jump(vector<int> &nums) {

    int n = nums.size();
    vector<int> c(n, 0);
    if (n == 1) {
      return 0;
    }
    int feet = 0;
    int cover = 0;
    int times = 0;
    int i = 0;
    int j = 0;
    while (i <= cover) {
      times++;
      feet = cover;
      for (; j <= feet; j++) {
        cover = max(cover, j + nums[j]);
        if (cover >= n - 1) {
          return times;
        }
      }
      i = j;
    }
    return times;
  }
};