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
  int rob(TreeNode *root) { return robsub(root); }

  int robsub(TreeNode *node) {
    if (node == nullptr) {
      return 0;
    }
    if (memo.find(node) != memo.end()) {
      return memo[node];
    }
    int res;
    if (node->left == nullptr && node->right == nullptr) {
      res = node->val;
    } else {
      int v1 = node->val;
      int v2 = 0;
      if (node->left != nullptr) {
        v1 += robsub(node->left->left);
        v1 += robsub(node->left->right);
        v2 += robsub(node->left);
      }
      if (node->right != nullptr) {
        v1 += robsub(node->right->left);
        v1 += robsub(node->right->right);
        v2 += robsub(node->right);
      }

      res = max(v1, v2);
    }
    memo[node] = res;
    return res;
  }

  unordered_map<TreeNode *, int> memo;
};