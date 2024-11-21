

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
  void flat(TreeNode *node) {
    if (node == nullptr) {
      return;
    }
    if (node->left == nullptr) {
      return;
    } else {
      if (node->right == nullptr) {
        node->right = node->left;
        node->left = nullptr;
      } else {
        TreeNode *tmp = node->right;
        node->right = node->left;
        node->left = nullptr;
        TreeNode *right_end = node->right;
        while (right_end->right != nullptr) {
          right_end = right_end->right;
        }
        right_end->right = tmp;
      }
    }
  }
  void flatten(TreeNode *root) {
    if (root == nullptr) {
      return;
    }
    if (root->left != nullptr) {
      flatten(root->left);
    }
    if (root->right != nullptr) {
      flatten(root->right);
    }
    flat(root);
  }
};

int main() {
  vector<int> Data = {1, 2, 5, 3, 4, null, 6};
  TreeNode *Root = NULL;
  Root = CreateTree(Data);
  cout << "PreOrder:" << endl;
  prePrint(Root);
  Solution solute;
  solute.flatten(Root);
  cout << "After flatten PreOrder:" << endl;
  prePrint(Root);
}