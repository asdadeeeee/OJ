struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
  ListNode *reverse(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }
    ListNode *new_head = reverse(head->next);
    head->next->next = head;
    head->next = nullptr;
    return new_head;
  }
  ListNode *reverseList(ListNode *head) { return reverse(head); }
};