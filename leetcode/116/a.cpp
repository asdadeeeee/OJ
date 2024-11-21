#include <queue>
#define NULL nullptr
class Node {
public:
  int val;
  Node *left;
  Node *right;
  Node *next;

  Node() : val(0), left(NULL), right(NULL), next(NULL) {}

  Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

  Node(int _val, Node *_left, Node *_right, Node *_next)
      : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
  Node *connect(Node *root) {
    if (root == NULL) {
      return root;
    }
    nodes.push(root);

    while (!nodes.empty()) {
      int size = nodes.size();
      for (int i = 0; i < size; i++) {
        const auto cur_node = nodes.front();
        nodes.pop();
        if (cur_node != NULL) {
          if (nodes.empty() || i == size - 1) {
            cur_node->next = NULL;
          } else {
            const auto &next = nodes.front();
            cur_node->next = next;
          }
          if (cur_node->left != NULL) {
            nodes.push(cur_node->left);
          }
          if (cur_node->right != NULL) {
            nodes.push(cur_node->right);
          }
        }
      }
    }

    return root;
  }

  std::queue<Node *> nodes;
};
