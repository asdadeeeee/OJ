#include <deque>
#include <stack>
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
  vector<int> rightSideView(TreeNode *root) {
    vector<int> ans;
    deque<TreeNode *> q;
    if (root == nullptr) {
      return ans;
    }
    q.push_back(root);
    while (!q.empty()) {
      int n = q.size();
      for (int i = 0; i < n; i++) {
        TreeNode *front = q.front();
        q.pop_front();
        if (front->left != nullptr) {
          q.push_back(front->left);
        }
        if (front->right != nullptr) {
          q.push_back(front->right);
        }
        if (i == n - 1) {
          ans.push_back(front->val);
        }
      }
    }
    return ans;
  }
};