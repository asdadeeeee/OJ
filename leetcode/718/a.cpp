#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
  int findLength(vector<int> &nums1, vector<int> &nums2) {
    int n = nums1.size();
    int m = nums2.size();
    int ans = -1;
    vector<int> dp(m, 0);
    for (int i = 0; i < m; i++) {
      if (nums1[n - 1] == nums2[i]) {
        dp[i] = 1;
        ans = max(ans, dp[i]);
      }
    }

    for (int i = n - 2; i >= 0; i--) {
      for (int j = 0; j <= m - 1; j++) {
        if (j == m - 1) {
          if (nums1[i] == nums2[j]) {
            dp[j] = 1;
          } else {
            dp[j] = 0;
          }
        } else {
          if (nums1[i] == nums2[j]) {
            dp[j] = dp[j + 1] + 1;
          } else {
            dp[j] = 0;
          }
        }
        ans = max(ans, dp[j]);
      }
    }
    return ans;
  }
};
int main() {
  vector<int> nums1 = {1, 2, 3, 4, 5};
  vector<int> nums2 = {9, 8, 7, 6, 5};
  Solution so;
  so.findLength(nums1, nums2);
}
