#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <ostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<string>> solveNQueens(int n) {
    n_ = n;
    dfs(0);
    return ans;
  }
  void dfs(int row) {
    for (int i = 0; i < n_; i++) {
      if (canbetaken(row, i)) {
        solute.emplace_back(make_pair(row, i));
        if (row == n_ - 1) {
          addans(solute);
        } else {
          dfs(row + 1);
        }
        solute.pop_back();
      }
    }
  }

  bool canbetaken(int row, int i) {
    for (const auto &p : solute) {
      if (p.first == row || p.second == i || in_a_line(p, row, i)) {
        return false;
      }
    }
    return true;
  }
  bool in_a_line(std::pair<int, int> p, int row, int i) {
    return row - p.first == abs(i - p.second);
  }
  void addans(const std::vector<std::pair<int, int>> &solute) {
    vector<string> res;
    for (const auto &p : solute) {
      int idx = p.second;
      string a = "";
      for (int i = 0; i < n_; i++) {
        if (i == idx) {
          a.append("Q");
        } else {
          a.append(".");
        }
      }
      res.emplace_back(a);
    }
    ans.emplace_back(res);
  }
  int n_;
  std::vector<std::pair<int, int>> solute;
  vector<vector<string>> ans;
};