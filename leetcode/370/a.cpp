#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  vector<int> getModifiedArray(int length, vector<vector<int>> &updates) {
    std::vector<int> res(length, 0);
    for (const auto &update : updates) {
      res[update[0]] = res[update[0]] + update[2];
      res[update[1] + 1] = res[update[1] + 1] - update[2];
    }
    for (int i = 1; i < length; i++) {
      res[i] = res[i - 1] + res[i];
    }
    return res;
  }
};
int main() {
  int length = 5;
  vector<vector<int>> updates = {{1, 3, 2}, {2, 4, 3}, {0, 2, -2}};
  Solution so;
  auto res = so.getModifiedArray(length, updates);
  for (auto r : res) {
    cout << r << " ";
  }
}