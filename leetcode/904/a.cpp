#include <algorithm>
#include <cstdlib>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
  int totalFruit(vector<int> &fruits) {
    int n = fruits.size();
    int left_ptr = 0;
    vector<int> cnt(n);
    int ans = 0;
    int kinds = 0;
    for (int right_ptr = 0; right_ptr < n; right_ptr++) {
      if (cnt[fruits[right_ptr]] == 0) {
        kinds++;
      }
      cnt[fruits[right_ptr]]++;
      while (kinds > 2) {
        cnt[fruits[left_ptr]]--;
        if (cnt[fruits[left_ptr]] == 0) {
          kinds--;
        }
        left_ptr++;
      }
      ans = max(ans, right_ptr - left_ptr + 1);
    }
    return ans;
  }
};