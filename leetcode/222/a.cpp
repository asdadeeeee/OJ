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
  bool exist(TreeNode *root, int n, int level) {

    TreeNode *node = root;
    int bits = 0;
    if (level >= 1) {
      bits = 1 << (level - 1);
    }
    while (bits > 0 && node != nullptr) {
      if ((bits & n) == 0) {
        node = node->left;
      } else {
        node = node->right;
      }
      bits = bits >> 1;
    }
    return node != nullptr;
  }
  int countNodes(TreeNode *root) {
    int level = 0;
    TreeNode *node = root;
    if (node == nullptr) {
      return 0;
    }
    while (node->left != nullptr) {
      node = node->left;
      level++;
    }
    int left = 1 << level;
    int right = (1 << (level + 1)) - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (exist(root, mid, level)) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return right;
  }
};