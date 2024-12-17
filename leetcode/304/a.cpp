#include <iostream>
#include <vector>
using namespace std;

class NumMatrix {
public:
  vector<vector<int>> sums;
  int row;
  int col;
  NumMatrix(vector<vector<int>> &matrix) {

    row = matrix.size();
    col = matrix.at(0).size();
    sums.resize(row + 1, vector<int>(col + 1));
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        sums[i + 1][j + 1] =
            sums[i][j + 1] + sums[i + 1][j] - sums[i][j] + matrix[i][j];
      }
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    return sums[row2 + 1][col2 + 1] - sums[row1][col2 + 1] -
           sums[row2 + 1][col1] + sums[row1][col1];
  }
};

int main() {
  vector<vector<int>> matrix = {{3, 0, 1, 4, 2},
                                {5, 6, 3, 2, 1},
                                {1, 2, 0, 1, 5},
                                {4, 1, 0, 1, 7},
                                {1, 0, 3, 0, 5}};

  NumMatrix numa{matrix};
  int suma = numa.sumRegion(2, 1, 4, 3);
  cout << suma;
}
