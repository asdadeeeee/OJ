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
  TreeNode *searchBST(TreeNode *root, int val) {

    if (root == nullptr || root->val == val) {
      return root;
    }
    if (val > root->val) {
      return searchBST(root->right, val);
    }
    if (val < root->val) {
      return searchBST(root->left, val);
    }
    return nullptr;
  }
};
