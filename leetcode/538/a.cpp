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
  TreeNode *convertBST(TreeNode *root) {
    travel(root);
    return root;
  }

  void travel(TreeNode *node) {
    if (node == nullptr) {
      return;
    }
    travel(node->right);
    sum += node->val;
    node->val = sum;
    travel(node->left);
  }
  int sum = 0;
};