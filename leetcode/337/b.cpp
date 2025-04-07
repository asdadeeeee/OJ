#include <algorithm>
#include <iostream>
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
  int rob(TreeNode *root) {
    auto p = robsub(root);
    return max(p.first, p.second);
  }

  pair<int, int> robsub(TreeNode *node) {
    if (node == nullptr) {
      return {0, 0};
    }
    auto left = robsub(node->left);
    auto right = robsub(node->right);
    int res1 = node->val + left.second + right.second;
    int res2 = max(left.first, left.second) + max(right.first, right.second);
    return {res1, res2};
  }
};