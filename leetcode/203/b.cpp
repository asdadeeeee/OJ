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
    ListNode *cur = dum;
    while (cur->next != nullptr) {
      if (cur->next->val == val) {
        ListNode *temp = cur->next;
        cur->next = temp->next;
        delete temp;
      } else {
        cur = cur->next;
      }
    }
    return dum->next;
  }
};