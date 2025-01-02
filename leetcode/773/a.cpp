#include <functional>
#include <queue>
#include <vector>
using namespace std;
class Solution {
public:
  int dx[4] = {0, 0, 1, -1};
  int dy[4] = {1, -1, 0, 0};
  int FAC[6] = {100000, 10000, 1000, 100, 10, 1};
  inline int mhash(vector<vector<int>> &board) {
    int hash = 0;
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 3; j++) {
        hash += board[i][j] * FAC[i * 3 + j];
      }
    }
    return hash;
  }

  inline void dehash(int hash, vector<vector<int>> &board) {
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 3; j++) {
        int t = hash / FAC[i * 3 + j];
        hash = hash % FAC[i * 3 + j];
        board[i][j] = t;
      }
    }
  }

  struct node {
    int x;
    int y;
    int hash;
  };
  inline bool bound(node n) {
    return n.x >= 0 && n.x <= 1 && n.y >= 0 && n.y <= 2;
  }
  inline bool bound(int x, int y) {
    return x >= 0 && x <= 1 && y >= 0 && y <= 2;
  }
  int slidingPuzzle(vector<vector<int>> &board) {
    int inf = 0x3f3f3f3f;
    vector<int> dist(543220, inf);
    queue<node> q;
    int hash = mhash(board);
    node start;
    start.hash = hash;
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 3; j++) {
        if (board[i][j] == 0) {
          start.x = i;
          start.y = j;
          break;
        }
      }
    }
    q.push(start);
    dist[start.hash] = 0;
    int target_hash = 123450;
    bfs(q, dist, target_hash);
    return dist[target_hash] == inf ? -1 : dist[target_hash];
  }

  void bfs(queue<node> &q, vector<int> &dist, int target_hash) {
    vector<vector<int>> cur_board = ori;
    while (!q.empty()) {
      node cur = q.front();
      if (cur.hash == target_hash) {
        return;
      }
      q.pop();
      for (int i = 0; i < 4; i++) {
        int nx = cur.x + dx[i];
        int ny = cur.y + dy[i];
        if (bound(nx, ny)) {
          dehash(cur.hash, cur_board);
          swap(cur_board[nx][ny], cur_board[cur.x][cur.y]);
          int hash = mhash(cur_board);
          if (dist[cur.hash] + 1 < dist[hash]) {
            dist[hash] = dist[cur.hash] + 1;
            q.push({nx, ny, hash});
          }
        }
      }
    }
  }

  vector<vector<int>> ori = {{0, 1, 2}, {3, 4, 5}};
};