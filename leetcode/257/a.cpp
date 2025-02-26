#include <algorithm>
#include <deque>
#include <stack>
#include <string>
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
  void visit(TreeNode *node, string cur, vector<string> &ans) {
    if (node == nullptr) {
      return;
    }
    cur += to_string(node->val);
    if (node->left == nullptr && node->right == nullptr) {
      ans.emplace_back(cur);
    }
    if (node->left != nullptr) {
      visit(node->left, cur + "->", ans);
    }
    if (node->right != nullptr) {
      visit(node->right, cur + "->", ans);
    }
  }
  vector<string> binaryTreePaths(TreeNode *root) {
    string s;
    vector<string> ans;
    visit(root, s, ans);
    return ans;
  }
};