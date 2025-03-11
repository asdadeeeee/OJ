#include <vector>
using namespace std;
class Solution {
public:
  void visit(vector<vector<int>> &ans, vector<int> &temp, int k, int n,
             int &sum, int cur) {
    if (temp.size() == k) {
      if (sum == n) {
        ans.emplace_back(temp);
      }
      return;
    }
    for (int i = cur; i < n / (k - temp.size()) && i <= 9; i++) {
      temp.push_back(i);
      sum += i;
      visit(ans, temp, k, n, sum, i + 1);
      sum -= i;
      temp.pop_back();
    }
  }
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> ans;
    vector<int> temp;
    int sum = 0;
    visit(ans, temp, k, n, sum, 1);
    return ans;
  }
};