#include <deque>
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
  int mind(TreeNode *node) {
    if (node == nullptr) {
      return 0;
    }
    if (node->left == nullptr && node->right == nullptr) {
      return 1;
    }
    if (node->left == nullptr) {
      return mind(node->right) + 1;
    }
    if (node->right == nullptr) {
      return mind(node->left) + 1;
    }
    int leftd = mind(node->left);
    int rightd = mind(node->right);
    return min(leftd, rightd) + 1;
  }
  int minDepth(TreeNode *root) { return mind(root); }
};