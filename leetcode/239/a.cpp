#include <deque>
#include <list>
#include <queue>
#include <vector>
using namespace std;
class MyQueue {
public:
  void push(int n) {
    while (!q.empty() && q.back() < n) {
      q.pop_back();
    }
    q.push_back(n);
  }

  int max() { return q.front(); }

  void pop(int n) {
    if (q.front() == n) {
      q.pop_front();
    }
  }
  deque<int> q;
};
class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    vector<int> ans;
    int ptr1 = 0;
    int ptr2 = k - 1;
    for (int i = ptr1; i <= ptr2; i++) {
      int n = nums[i];
      m.push(n);
    }
    ans.emplace_back(m.max());
    while (ptr2 < nums.size() - 1) {
      m.pop(nums[ptr1]);
      ptr1++;
      ptr2++;
      int n = nums[ptr2];
      m.push(n);
      ans.emplace_back(m.max());
    }
    return ans;
  }

  MyQueue m;
};