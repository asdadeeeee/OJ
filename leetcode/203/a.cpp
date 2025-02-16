

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *removeElements(ListNode *head, int val) {
    ListNode *dum = new ListNode(0, head);
    ListNode *ptr1 = dum;
    ListNode *ptr2 = dum->next;
    while (ptr1 != nullptr) {
      while (ptr2 != nullptr && ptr2->val == val) {
        ptr2 = ptr2->next;
      }
      ptr1->next = ptr2;
      ptr1 = ptr1->next;
      if (ptr2 != nullptr) {
        ptr2 = ptr2->next;
      }
    }
    return dum->next;
  }
};