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
  TreeNode *build(vector<int> &inorder, int instart, int inend,
                  vector<int> &postorder, int poststart, int postend) {
    if (instart > inend || poststart > postend) {
      return nullptr;
    }
    int rootval = postorder[postend];
    int inidx = m[rootval];

    auto node = new TreeNode{rootval};
    int left_size = inidx - instart;
    int right_size = inend - inidx;

    node->left = build(inorder, instart, inidx - 1, postorder, poststart,
                       poststart + left_size - 1);
    node->right =
        build(inorder, inidx + 1, inend, postorder, poststart + left_size,
              poststart + left_size + right_size - 1);
    return node;
  };
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    for (int i = 0; i < inorder.size(); i++) {
      m[inorder[i]] = i;
    }
    return build(inorder, 0, inorder.size() - 1, postorder, 0,
                 postorder.size() - 1);
  }
  unordered_map<int, int> m;
};