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
    ListNode *ptr1 = dum;
    ListNode *ptr2 = ptr1;
    for (int i = 0; i < n; i++) {
      ptr2 = ptr2->next;
    }
    while (ptr2->next != nullptr) {
      ptr1 = ptr1->next;
      ptr2 = ptr2->next;
    }
    ListNode *temp = ptr1->next;
    ptr1->next = temp->next;
    delete temp;
    return dum->next;
  }
};