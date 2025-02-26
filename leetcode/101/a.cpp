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
  bool compare(TreeNode *left, TreeNode *right) {
    if (left == nullptr && right == nullptr) {
      return true;
    } else if (left != nullptr && right == nullptr) {
      return false;
    } else if (left == nullptr && right != nullptr) {
      return false;
    } else if (left->val != right->val) {
      return false;
    }
    bool out = compare(left->left, right->right);
    bool in = compare(left->right, right->left);
    return out && in;
  }
  bool isSymmetric(TreeNode *root) {
    if (root == nullptr) {
      return true;
    } else {
      return compare(root->left, root->right);
    }
  }
};