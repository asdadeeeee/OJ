#include <cstddef>
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
  TreeNode *build(vector<int> &preorder, int prestart, int preend,
                  vector<int> &postorder, int poststart, int postend) {
    if (prestart > preend || poststart > postend) {
      return nullptr;
    }
    int rootvalue = preorder[prestart];
    auto node = new TreeNode{rootvalue};
    if (prestart == preend) {
      return node;
    }
    int left_root_idx = m[preorder[prestart + 1]];
    int left_size = left_root_idx - poststart + 1;
    int right_size = postend - left_root_idx - 1;
    node->left = build(preorder, prestart + 1, prestart + left_size, postorder,
                       poststart, left_root_idx);
    node->right = build(preorder, prestart + left_size + 1, preend, postorder,
                        left_root_idx + 1, postend - 1);
    return node;
  };
  TreeNode *constructFromPrePost(vector<int> &preorder,
                                 vector<int> &postorder) {
    for (int i = 0; i < postorder.size(); i++) {
      m[postorder[i]] = i;
    }
    return build(preorder, 0, preorder.size() - 1, postorder, 0,
                 postorder.size() - 1);
  }
  unordered_map<int, int> m;
};