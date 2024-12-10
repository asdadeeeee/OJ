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
    ListNode *dummy = new ListNode(0, head);
    ListNode *ptr1 = dummy;
    ListNode *ptr2 = head;
    while (n--) {
      ptr2 = ptr2->next;
    }

    while (ptr2 != nullptr) {
      ptr2 = ptr2->next;
      ptr1 = ptr1->next;
    }

    ptr1->next = ptr1->next->next;
    ListNode *ans = dummy->next;
    delete dummy;
    return ans;
  }
};
