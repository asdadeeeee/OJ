#include <utility>
#include <vector>

using namespace std;
class Solution {

public:
  int n, m;
  vector<int> visit;
  vector<int> dx = {0, 1, 0, -1};
  vector<int> dy = {1, 0, -1, 0};
  bool bound(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && visit[x * m + y] == 0;
  }
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    n = matrix.size();
    m = matrix[0].size();

    visit.resize(n * m, 0);
    vector<int> ans;
    if (n == 0 || m == 0) {
      return ans;
    }
    int curx = 0;
    int cury = 0;

    int way = 0;
    while (bound(curx, cury)) {
      visit[curx * m + cury] = 1;
      ans.emplace_back(matrix[curx][cury]);
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