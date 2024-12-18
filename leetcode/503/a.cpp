#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
  vector<int> nextGreaterElements(vector<int> &nums) {
    vector<int> ans(nums.size());
    int size = nums.size();
    for (int i = size * 2 - 1; i >= 0; i--) {
      int t = nums[i % size];
      while (!A.empty() && t >= A.top()) {
        A.pop();
      }
      //   ans[t] = A.empty() ? -1 : A.top();
      ans[i % size] = A.empty() ? -1 : A.top();
      A.push(t);
    }
    return ans;
  }
  stack<int> A;
};