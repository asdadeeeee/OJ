
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

  inline bool bound(vector<vector<char>> &board, int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
  }

  inline bool atbound(vector<vector<char>> &board, int x, int y) {
    return x == 0 || x == n - 1 || y == 0 || y == m - 1;
  }
  void solve(vector<vector<char>> &board) {
    n = board.size();
    m = board[0].size();
    can_trans.resize(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (board[i][j] == 'O' && atbound(board, i, j) && !can_trans[i][j]) {
          dfs(board, {i, j});
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (!can_trans[i][j]) {
          board[i][j] = 'X';
        }
      }
    }
  }

  void dfs(vector<vector<char>> &board, node cur) {
    can_trans[cur.x][cur.y] = true;
    for (int i = 0; i < 4; i++) {
      int nx = cur.x + dx[i];
      int ny = cur.y + dy[i];
      if (bound(board, nx, ny) && !can_trans[nx][ny] && board[nx][ny] == 'O') {
        dfs(board, {nx, ny});
      }
    }
  }

  int n;
  int m;
  vector<vector<bool>> can_trans;
};

int main() {
  vector<vector<char>> board{{'X', 'X', 'X', 'X'},
                             {'X', 'O', 'O', 'X'},
                             {'X', 'X', 'O', 'X'},
                             {'X', 'O', 'X', 'X'}};
  Solution so;
  so.solve(board);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << board[i][j];
    }
    cout << endl;
  }
}