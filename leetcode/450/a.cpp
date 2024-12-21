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
  TreeNode *getMin(TreeNode *node) {
    while (node->left != nullptr) {
      node = node->left;
    }
    return node;
  }
  TreeNode *deleteNode(TreeNode *root, int key) {
    if (root == nullptr) {
      return nullptr;
    }
    if (key == root->val) {
      if (root->left == nullptr) {
        return root->right;
      } else if (root->right == nullptr) {
        return root->left;
      }
      TreeNode *min = getMin(root->right);
      root->right = deleteNode(root->right, min->val);
      min->left = root->left;
      min->right = root->right;
      root = min;
    } else if (key > root->val) {
      root->right = deleteNode(root->right, key);
    } else if (key < root->val) {
      root->left = deleteNode(root->left, key);
    }
    return root;
  }
};
