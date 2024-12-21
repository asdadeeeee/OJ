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
  int kthSmallest(TreeNode *root, int k) {
    travel(root, k);
    return res;
  }

  void travel(TreeNode *node, int k) {
    if (node == nullptr) {
      return;
    }
    travel(node->left, k);
    rank++;
    if (rank == k) {
      res = node->val;
      return;
    }
    travel(node->right, k);
  }

  int res;
  int rank;
};