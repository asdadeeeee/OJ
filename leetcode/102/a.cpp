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
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> ans;
    deque<TreeNode *> st;
    if (root == nullptr) {
      return ans;
    }
    st.push_back(root);
    while (!st.empty()) {
      int n = st.size();
      vector<int> cur;
      for (int i = 0; i < n; i++) {
        TreeNode *front = st.front();
        st.pop_front();
        if (front != nullptr) {
          cur.emplace_back(front->val);
          if (front->left != nullptr) {
            st.push_back(front->left);
          }
          if (front->right != nullptr) {
            st.push_back(front->right);
          }
        }
      }
      ans.emplace_back(cur);
    }
    return ans;
  }
};
