#include <deque>
#include <functional>
#include <queue>
#include <vector>
using namespace std;
class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    int n = nums.size();
    vector<int> ans;
    myqueue q;
    int left = 0;
    int right = k - 1;
    for (int i = left; i <= right; i++) {
      q.push(nums[i]);
    }
    ans.push_back(q.top());
    while (right < n - 1) {
      if (nums[left] == q.top()) {
        q.pop();
      }
      left++;
      right++;
      q.push(nums[right]);
      ans.push_back(q.top());
    }

    return ans;
  }

private:
  class myqueue {
  public:
    deque<int> q;
    int pop() {
      int top = q.front();
      q.pop_front();
      return top;
    }
    int top() { return q.front(); }

    void push(int x) {
      while (!q.empty() && q.back() < x) {
        q.pop_back();
      }
      q.push_back(x);
    }
    bool empty() { return q.empty(); }
  };
};
