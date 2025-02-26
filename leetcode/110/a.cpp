
#include <algorithm>
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
  int getHeight(TreeNode *node) {
    if (node == nullptr) {
      return 0;
    }
    if (node->left == nullptr && node->right == nullptr) {
      return 1;
    }
    int lefth = getHeight(node->left);
    int righth = getHeight(node->right);
    if (lefth == -1 || righth == -1) {
      return -1;
    }
    int maxh = max(lefth, righth);
    int minh = min(lefth, righth);
    return maxh - minh > 1 ? -1 : maxh + 1;
  }
  bool isBalanced(TreeNode *root) {
    int res = getHeight(root);
    return res != -1;
  }
};