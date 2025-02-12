#include <algorithm>
#include <functional>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  struct cmp {
    bool operator()(const pair<int, int> &p1, const pair<int, int> &p2) {
      return p1.second <= p2.second;
    }
  };
  vector<int> advantageCount(vector<int> &nums1, vector<int> &nums2) {
    int n = nums1.size();
    vector<int> ans(n, 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    for (int i = 0; i < n; i++) {
      pq.emplace(i, nums2[i]);
    }
    sort(nums1.begin(), nums1.end(), greater<int>());
    int ptr1 = 0;
    int ptr2 = n - 1;
    while (!pq.empty()) {
      auto cur = pq.top();
      pq.pop();
      if (nums1[ptr1] > cur.second) {
        ans[cur.first] = nums1[ptr1];
        ptr1++;
      } else {
        ans[cur.first] = nums1[ptr2];
        ptr2--;
      }
    }
    return ans;
  }
};

int main() {
  vector<int> nums1 = {12, 24, 8, 32};
  vector<int> nums2 = {13, 25, 32, 11};
  Solution so;
  so.advantageCount(nums1, nums2);
}