#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> combine(int n, int k) {
    vector<int> temp;
    vector<vector<int>> ans;
    dfs(ans, temp, 1, n, k);
    return ans;
  }

  void dfs(vector<vector<int>> &ans, vector<int> &temp, int cur, int n, int k) {
    if (temp.size() == k) {
      ans.emplace_back(temp);
    }
    for (int i = cur; i <= n; i++) {
      if (temp.size() < k) {
        temp.emplace_back(i);
      } else {
        return;
      }
      dfs(ans, temp, i + 1, n, k);
      temp.pop_back();
    }
  }
};