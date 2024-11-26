

#include <iostream>
#include <queue>
#include <string>
#include <type_traits>
#include <vector>
using namespace std;

#define null 65535
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
TreeNode *CreateTree(vector<int> Data) {
  vector<string> str_data(Data.size(), "");
  for (int i = 0; i < Data.size(); i++) {
    if (Data[i] != null)
      str_data[i] = to_string(Data[i]);
    else
      str_data[i] = "null";
  }
  queue<TreeNode *> q;
  TreeNode *head = new TreeNode(stoi(str_data[0]));
  q.push(head);
  int i = 1;
  while (i < str_data.size()) {
    TreeNode *tmp = q.front();
    q.pop();
    if (str_data[i] != "null") {
      TreeNode *new_node = new TreeNode(stoi(str_data[i]));
      tmp->left = new_node;
      q.push(new_node);
    }
    i++;
    if (str_data[i] != "null") {
      TreeNode *new_node = new TreeNode(stoi(str_data[i]));
      tmp->right = new_node;
      q.push(new_node);
    }
    i++;
  }
  return head;
}

void prePrint(TreeNode *Root) { //先序遍历
  if (Root == NULL)
    return;
  cout << Root->val << ',';
  prePrint(Root->left);
  prePrint(Root->right);
  return;
}

class Solution {
public:
  vector<int> preorderTraversal(TreeNode *root) {
    vector<int> res;
    pre(root, res);
    return res;
  }

  void pre(TreeNode *root, vector<int> &ans) {
    if (root == nullptr) {
      return;
    }
    ans.push_back(root->val);
    pre(root->left, ans);
    pre(root->right, ans);
  }
};

int main() {
  vector<int> Data = {1, 2, 5, 3, 4, null, 6};
  TreeNode *Root = NULL;
  Root = CreateTree(Data);
  cout << "PreOrder:" << endl;
  prePrint(Root);
  cout << "After flatten PreOrder:" << endl;
  prePrint(Root);
}