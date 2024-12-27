
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
class Solution {
public:
  struct node {
    int x;
    int y;
  };

  bool bound(vector<vector<char>> &board, int x, int y) {
    return x >= 0 && x < board.size() && y >= 0 && y < board[0].size();
  }

  bool atbound(vector<vector<char>> &board, int x, int y) {
    return x == 0 || x == board.size() - 1 || y == 0 ||
           y == board[0].size() - 1;
  }
  void solve(vector<vector<char>> &board) {
    can_trans.resize(board.size(), vector<bool>(board[0].size(), true));
    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[0].size(); j++) {
        if (board[i][j] == 'O' && can_trans[i][j]) {
          bfs(board, {i, j});
        }
      }
    }
  }

  void bfs(vector<vector<char>> &board, node n) {
    bool at_bound = false;
    res.clear();
    q.push(n);
    while (!q.empty()) {
      node cur = q.front();
      res.emplace_back(cur);
      q.pop();
      if (atbound(board, cur.x, cur.y)) {
        at_bound = true;
      }
      for (int i = 0; i < 4; i++) {
        int nx = cur.x + dx[i];
        int ny = cur.y + dy[i];
        if (bound(board, nx, ny) && board[nx][ny] == 'O' &&
            can_trans[nx][ny] == true) {
          q.push({nx, ny});
          can_trans[nx][ny] = false;
        }
      }
    }
    if (!at_bound) {
      for (auto temp : res) {
        board[temp.x][temp.y] = 'X';
      }
    }
    return;
  }
  vector<node> res;
  queue<node> q;
  vector<vector<bool>> can_trans;
};

int main() {
  vector<vector<char>> board{{'X', 'X', 'X', 'X'},
                             {'X', 'O', 'O', 'X'},
                             {'X', 'X', 'O', 'X'},
                             {'X', 'O', 'X', 'X'}};
  Solution so;
  so.solve(board);
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[0].size(); j++) {
      cout << board[i][j];
    }
    cout << endl;
  }
}