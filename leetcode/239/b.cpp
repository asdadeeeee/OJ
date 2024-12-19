#include <deque>
#include <list>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    vector<int> ans;
    deque<int> index;
    for (int i = 0; i < nums.size(); i++) {
      int n = nums[i];
      while (!index.empty() && nums[index.back()] < n) {
        index.pop_back();
      }
      index.push_back(i);
      if (i - index.front() >= k) {
        index.pop_front();
      }
      if (i >= k - 1) {
        ans.push_back(nums[index.front()]);
      }
    }
    return ans;
  }
};