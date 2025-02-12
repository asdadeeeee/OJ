#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

struct cmp {
  bool operator()(const pair<int, int> &p1, const pair<int, int> &p2) {
    return p1.second <= p2.second; // 降序排列
  }
};

int main() {
  vector<int> nums2 = {13, 25, 32, 11};
  priority_queue<pair<int, int>, vector<pair<int, int>>, less<>> pq;

  for (int i = 0; i < nums2.size(); i++) {
    pq.push({i, nums2[i]});
  }

  while (!pq.empty()) {
    cout << "Index: " << pq.top().first << ", Value: " << pq.top().second
         << endl;
    pq.pop();
  }

  return 0;
}