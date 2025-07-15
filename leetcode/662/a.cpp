#include <deque>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
class Solution {
public:
  int widthOfBinaryTree(TreeNode *root) {
    queue<pair<TreeNode *, unsigned long long>> A;
    unsigned long long ans = 0;
    if (root == nullptr) {
      return 0;
    }
    A.push({root, 1});
    while (!A.empty()) {
      int n = A.size();
      unsigned long long left_idx = A.front().second;
      unsigned long long right_idx = A.back().second;
      ans = max(ans, right_idx - left_idx + 1);
      for (int i = 0; i < n; i++) {
        auto p = A.front();
        A.pop();
        unsigned long long p_idx = p.second;
        if (p.first->left != nullptr) {
          A.push({p.first->left, 2 * p_idx});
        }
        if (p.first->right != nullptr) {
          A.push({p.first->right, 2 * p_idx + 1});
        }
      }
    }
    return ans;
  }
};
