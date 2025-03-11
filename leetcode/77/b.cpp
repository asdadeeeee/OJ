#include <vector>
using namespace std;
class Solution {
public:
  void visit(int cur, int n, int k, vector<int> &temp,
             vector<vector<int>> &ans) {
    if (temp.size() == k) {
      ans.emplace_back(temp);
      return;
    }
    for (int i = cur; i <= n; i++) {
      temp.push_back(i);
      visit(i + 1, n, k, temp, ans);
      temp.pop_back();
    }
  }
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ans;
    vector<int> temp;
    visit(1, n, k, temp, ans);
    return ans;
  }
};

int main() {
  Solution so;
  so.combine(4, 2);
}