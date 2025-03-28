#include <vector>
using namespace std;
class NumMatrix {
public:
  vector<vector<int>> s;
  NumMatrix(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    s.resize(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        s[i][j] =
            s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + matrix[i - 1][j - 1];
      }
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    return s[row2 + 1][col2 + 1] - s[row1][col2 + 1] - s[row2 + 1][col1] +
           s[row1][col1];
  }
};