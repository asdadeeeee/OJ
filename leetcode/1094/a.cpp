#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  bool carPooling(vector<vector<int>> &trips, int capacity) {
    std::vector<int> res(1002, 0);
    int des = 0;
    for (const auto &trip : trips) {
      res[trip[1]] += trip[0];
      res[trip[2]] -= trip[0];
      des = max(des, trip[2]);
    }
    for (int i = 0; i <= des; i++) {
      if (i != 0) {
        res[i] += res[i - 1];
      }
      if (res[i] > capacity) {
        return false;
      }
    }
    return true;
  }
};