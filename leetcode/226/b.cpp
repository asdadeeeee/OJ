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
  TreeNode *invert(TreeNode *node) {
    if (node == nullptr || (node->left == nullptr && node->right == nullptr)) {
      return node;
    }
    TreeNode *new_left = invert(node->left);
    TreeNode *new_right = invert(node->right);
    node->right = new_left;
    node->left = new_right;
    return node;
  }
  TreeNode *invertTree(TreeNode *root) { return invert(root); }
};