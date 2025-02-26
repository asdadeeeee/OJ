#include <iostream>
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
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *dum = new ListNode(0, head);
    ListNode *left = dum;
    ListNode *right = dum;
    while (n--) {
      right = right->next;
    }
    while (right->next != nullptr) {
      left = left->next;
      right = right->next;
    }
    ListNode *temp = left->next;
    left->next = temp->next;
    delete temp;
    return dum->next;
  }
};