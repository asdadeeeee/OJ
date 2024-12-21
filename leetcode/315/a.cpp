#include <utility>
#include <vector>
using namespace std;
class Solution {
public:
  vector<int> countSmaller(vector<int> &nums) {
    ans.resize(nums.size());
    for (int i = 0; i < nums.size(); i++) {
      info.emplace_back(nums[i], i);
    }
    temp.resize(info.size());
    sort(0, nums.size() - 1);
    return ans;
  }
  void sort(int start, int end) {
    if (start >= end) {
      return;
    }
    int mid = start + (end - start) / 2;
    sort(start, mid);
    sort(mid + 1, end);
    merge(start, end, mid);
  }
  void merge(int start, int end, int mid) {
    int count = 0;
    int ptr1 = start;
    int ptr2 = mid + 1;
    while (ptr1 <= mid && ptr2 <= end) {
      if (info[ptr1].first <= info[ptr2].first) {
        temp[count++] = info[ptr1++];
        ans[info[ptr1 - 1].second] += ptr2 - mid - 1;
      } else {
        temp[count++] = info[ptr2++];
      }
    }
    while (ptr1 <= mid) {
      temp[count++] = info[ptr1++];
      ans[info[ptr1 - 1].second] += ptr2 - mid - 1;
    }
    while (ptr2 <= end) {
      temp[count++] = info[ptr2++];
    }
    for (int i = 0; i < end - start + 1; i++) {
      info[start + i] = temp[i];
    }
  }
  vector<pair<int, int>> info;
  vector<pair<int, int>> temp;
  vector<int> ans;
};