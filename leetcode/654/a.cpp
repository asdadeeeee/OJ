#include <cstddef>
#include <iostream>
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
  TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
    int size = nums.size();
    if (size <= 0) {
      return nullptr;
    }
    int max_idx = -1;
    int temp_max = -1;
    auto iter = nums.begin();
    auto temp_max_it = nums.end();
    for (; iter < nums.end(); iter++) {
      if (*iter > temp_max) {
        temp_max = *iter;
        temp_max_it = iter;
      }
    }
    auto node = new TreeNode{temp_max};
    vector<int> left_nums(nums.begin(), temp_max_it);
    vector<int> right_nums(++temp_max_it, nums.end());
    node->left = constructMaximumBinaryTree(left_nums);
    node->right = constructMaximumBinaryTree(right_nums);
    return node;
  }
};

void prePrint(TreeNode *Root) { //先序遍历
  if (Root == NULL)
    return;
  cout << Root->val << ',';
  prePrint(Root->left);
  prePrint(Root->right);
  return;
}
int main() {
  Solution so;
  vector<int> nums = {3, 2, 1, 6, 0, 5};
  auto root = so.constructMaximumBinaryTree(nums);
  prePrint(root);
}
