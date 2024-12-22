#include <cmath>
#include <iostream>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;
class Solution {
public:
  int maxDistinctElements(vector<int> &nums, int k) {
    for (auto n : nums) {
      int tl = n - k;
      int tr = n + k;
      bool found = false;
      for (int i = 0; i < regions.size(); i++) {
        if (tl <= regions[i].second && tr >= regions[i].first) {
          found = true;
          regions[i].first = min(tl, regions[i].first);
          regions[i].second = max(tr, regions[i].second);
          if (cap[i] + 1 <= regions[i].second - regions[i].first + 1) {
            cap[i]++;
          }
        }
      }

      if (!found) {
        regions.push_back({tl, tr});
        if (cap[regions.size() - 1] + 1 <=
            regions[regions.size() - 1].second -
                regions[regions.size() - 1].first + 1) {
          cap[regions.size() - 1]++;
        }
      }
    }
    int count = 0;
    for (auto n : nums) {
      for (auto &c : cap) {
        if (c.second > 0 && regions[c.first].first <= n &&
            regions[c.first].second >= n) {
          count++;
          c.second--;
          break;
        }
      }
    }
    return count;
  }
  vector<pair<int, int>> regions;
  unordered_map<int, int> cap;
};

int main() {
  vector<int> nums{10, 7, 7, 9, 7, 7, 8};
  Solution so;
  cout << so.maxDistinctElements(nums, 1);
}