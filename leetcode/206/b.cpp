
#include <cstddef>
#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    ListNode *ptr = head;
    ListNode *root = nullptr;
    while (ptr != nullptr) {
      ListNode *node = new ListNode(ptr->val);
      node->next = root;
      root = node;
      ptr = ptr->next;
    }
    return root;
  }
};