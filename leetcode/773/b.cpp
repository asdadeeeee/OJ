#include <array>
#include <functional>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;
using PuzzleState = std::array<std::array<int, 3>, 2>;
class Solution {
public:
  int dir[5] = {0, 1, 0, -1, 0};

  inline bool bound(int x, int y) {
    return x >= 0 && x <= 1 && y >= 0 && y <= 2;
  }
  int slidingPuzzle(vector<vector<int>> &board) {
    queue<PuzzleState> q;
    set<PuzzleState> step;
    PuzzleState start;
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 3; j++) {
        start[i][j] = board[i][j];
      }
    }
    PuzzleState target = {{{1, 2, 3}, {4, 5, 0}}};
    q.push(start);
    step.insert(start);
    int res = 0;
    while (!q.empty()) {
      int size = q.size();
      for (int i = 0; i < size; i++) {
        auto cur = q.front();
        if (cur == target) {
          return res;
        }
        q.pop();
        int curx = 0;
        int cury = 0;
        for (int i = 0; i < 6; i++) {
          if (cur[i / 3][i % 3] == 0) {
            curx = i / 3;
            cury = i % 3;
          }
        }
        for (int i = 0; i < 4; i++) {
          int nx = curx + dir[i];
          int ny = cury + dir[i + 1];
          if (bound(nx, ny)) {
            PuzzleState s = cur;
            swap(s[nx][ny], s[curx][cury]);
            if (step.find(s) == step.end()) {
              step.insert(s);
              q.push(s);
            }
          }
        }
      }
      res++;
    }
    return -1;
  }
};

int main() {
  vector<vector<int>> nums = {{1, 2, 3}, {4, 0, 5}};
  Solution so;
  cout << so.slidingPuzzle(nums);
  return 0;
}