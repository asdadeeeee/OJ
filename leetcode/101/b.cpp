#include <queue>
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
  bool isSymmetric(TreeNode *root) {
    queue<TreeNode *> q;
    if (root == nullptr) {
      return true;
    }
    q.push(root->left);
    q.push(root->right);
    while (!q.empty()) {
      TreeNode *left = q.front();
      q.pop();
      TreeNode *right = q.front();
      q.pop();
      if (left == nullptr && right == nullptr) {
        continue;
      }
      if ((left != nullptr && right == nullptr) ||
          (left == nullptr && right != nullptr) || (left->val != right->val)) {
        return false;
      }
      q.push(left->left);
      q.push(right->right);
      q.push(left->right);
      q.push(right->left);
    }
    return true;
  }
};