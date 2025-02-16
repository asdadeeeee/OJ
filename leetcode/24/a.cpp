struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
  ListNode *swap(ListNode *left) {
    ListNode *right = left->next;
    left->next = right->next;
    right->next = left;
    return right;
  }
  ListNode *swapPairs(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }
    ListNode *t = swapPairs(head->next->next);
    ListNode *new_head = swap(head);
    new_head->next->next = t;
    return new_head;
  }
};