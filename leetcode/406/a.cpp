#include <algorithm>
#include <vector>
using namespace std;
struct cmp {
  bool operator()(const vector<int> &a, const vector<int> &b) {
    return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
  }
};
class Solution {
public:
  vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
    sort(people.begin(), people.end(), cmp());
    vector<vector<int>> ans;
    ans.reserve(people.size());
    for (const auto &p : people) {
      ans.insert(ans.begin() + p[1], p);
    }
    return ans;
  }
};