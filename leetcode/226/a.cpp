

#include <type_traits>
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
  // void invert(TreeNode *node) {
  //   if (node != nullptr) {
  //     std::swap(node->left, node->right);
  //   }
  // }
  TreeNode *invertTree(TreeNode *root) {
    if (root != nullptr) {
      if (root->left != nullptr || root->right != nullptr) {
        TreeNode *left_temp = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(left_temp);
      }
    }
    return root;
  }
};