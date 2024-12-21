#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
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
  bool isValidBST(TreeNode *root) { return valid(root, nullptr, nullptr); }

  bool valid(TreeNode *node, TreeNode *min, TreeNode *max) {
    if (node == nullptr) {
      return true;
    }
    if (min != nullptr && node->val <= min->val) {
      return false;
    }
    if (max != nullptr && node->val >= max->val) {
      return false;
    }
    return valid(node->left, min, node) && valid(node->right, node, max);
  }
};