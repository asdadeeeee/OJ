#include <utility>
#include <vector>

using namespace std;
class Solution {
public:
  int N;
  vector<vector<int>> visit;
  vector<int> dx = {0, 1, 0, -1};
  vector<int> dy = {1, 0, -1, 0};
  bool bound(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N && visit[x][y] == 0;
  }
  vector<vector<int>> generateMatrix(int n) {
    N = n;
    vector<vector<int>> ans(n, vector<int>(n));
    visit.resize(n, vector<int>(n, 0));
    int curx = 0;
    int cury = 0;
    int val = 1;
    int way = 0;
    while (bound(curx, cury)) {
      ans[curx][cury] = val;
      visit[curx][cury] = 1;
      val++;
      int nextx = curx + dx[way % 4];
      int nexty = cury + dy[way % 4];
      if (!bound(nextx, nexty)) {
        way++;
        nextx = curx + dx[way % 4];
        nexty = cury + dy[way % 4];
      }
      curx = nextx;
      cury = nexty;
    }
    return ans;
  }
};