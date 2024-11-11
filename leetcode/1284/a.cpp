#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <ostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

// int bfs(Point p) {
//   sig[p.z][p.x][p.y] = 0;
//   points.push(p);
//   while (!points.empty()) {
//     Point p = points.front();
//     points.pop();
//     if (p.x == ex && p.y == ey && p.z == ez) {
//       break;
//     }

//     for (int i = 0; i < 6; i++) {
//       int nx = p.x + dx[i];
//       int ny = p.y + dy[i];
//       int nz = p.z + dz[i];
//       Point np{nz, nx, ny};
//       if (sig[nz][nx][ny] == inf && valid(np)) {
//         points.push(np);
//         sig[nz][nx][ny] = sig[p.z][p.x][p.y] + 1;
//       }
//     }
//   }
//   return sig[ez][ex][ey];
// }

class Solution {
public:
  int minFlips(vector<vector<int>> &mat) {
    bfs_que_.push(mat);
    mat_set_.insert(mat);
    if (AllZero(mat)) {
      return ans_;
    }
    while (!bfs_que_.empty()) {

      ans_++;
      int length = bfs_que_.size();
      for (int k = 0; k < length; k++) {
        auto cur_mat = bfs_que_.front();
        bfs_que_.pop();
        for (int i = 0; i < mat.size(); i++) {
          for (int j = 0; j < mat[0].size(); j++) {
            reverse(cur_mat, i, j);
            if (AllZero(cur_mat)) {
              return ans_;
            }
            if (mat_set_.find(cur_mat) == mat_set_.end()) {
              mat_set_.insert(cur_mat);
              bfs_que_.push(cur_mat);
            }
            reverse(cur_mat, i, j);
          }
        }
      }
    }
    return -1;
  }

private:
  queue<vector<vector<int>>> bfs_que_;
  set<vector<vector<int>>> mat_set_;
  int ans_ = 0;
  static constexpr int dx[5] = {-1, 0, 1, 0, 0};
  static constexpr int dy[5] = {0, 0, 0, 1, -1};
  void reverse(vector<vector<int>> &mat, int x, int y) {
    for (int i = 0; i < 5; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (bound(mat, nx, ny)) {
        mat[nx][ny] ^= 1;
      }
    }
  }
  bool AllZero(vector<vector<int>> &mat) {
    for (const auto &row : mat) {
      for (const auto &item : row) {
        if (item == 1) {
          return false;
        }
      }
    }
    return true;
  }

  bool bound(vector<vector<int>> &mat, int x, int y) {
    if (x >= 0 && x < mat.size() && y >= 0 && y < mat[0].size()) {
      return true;
    }
    return false;
  }
};