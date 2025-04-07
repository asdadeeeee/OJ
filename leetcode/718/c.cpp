#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
  int findLength(vector<int> &nums1, vector<int> &nums2) {
    int n = nums1.size();
    int m = nums2.size();
    vector<int> dp(m + 1, 0);
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = m; j >= 1; j--) {
        if (nums1[i] == nums2[j - 1]) {
          dp[j] = dp[j - 1] + 1;
        } else {
          dp[j] = 0;
        }
        ans = max(ans, dp[j]);
      }
    }
    return ans;
  }
};
