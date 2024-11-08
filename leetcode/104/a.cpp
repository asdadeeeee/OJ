

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
  int maxDepth(TreeNode *root) {
    dfs(root, 0);
    return max_;
  }

  void dfs(TreeNode *root, int n) {
    if (n > max_) {
      max_ = n;
    }
    if (root == nullptr) {
      return;
    } else {
      dfs(root->left, n + 1);
      dfs(root->right, n + 1);
    }
  }
  int max_ = 0;
};