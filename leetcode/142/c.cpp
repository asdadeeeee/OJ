
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    ListNode *ptr1 = head;
    ListNode *ptr2 = head;
    while (ptr1 != nullptr) {
      ptr2 = ptr2->next;
      if (ptr2 == nullptr || ptr2->next == nullptr) {
        return nullptr;
      }
      ptr2 = ptr2->next;
      ptr1 = ptr1->next;
      if (ptr2 == ptr1) {
        ListNode *ans = head;
        while (ans != ptr1) {
          ans = ans->next;
          ptr1 = ptr1->next;
        }
        return ans;
      }
    }
    return nullptr;
  }
};