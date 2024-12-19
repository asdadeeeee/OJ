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
                  vector<int> &inorder, int instart, int inend) {
    if (prestart > preend || instart > inend) {
      return nullptr;
    }
    int rootval = preorder[prestart];
    int inidx = m[rootval];
    auto node = new TreeNode{rootval};

    int left_size = inidx - instart;
    int right_size = inend - inidx;

    node->left = build(preorder, prestart + 1, prestart + left_size, inorder,
                       instart, inidx - 1);
    node->right = build(preorder, prestart + left_size + 1, preend, inorder,
                        inidx + 1, inend);
    return node;
  }
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    for (int i = 0; i < inorder.size(); i++) {
      m[inorder[i]] = i;
    }
    return build(preorder, 0, preorder.size() - 1, inorder, 0,
                 inorder.size() - 1);
  }

  unordered_map<int, int> m;
};