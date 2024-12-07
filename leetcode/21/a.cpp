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
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode *ptr1 = list1;
    ListNode *ptr2 = list2;
    auto head = new ListNode;
    ListNode *ptr = head;
    while (ptr1 != nullptr && ptr2 != nullptr) {
      if (ptr1->val <= ptr2->val) {
        ptr->next = ptr1;
        ptr1 = ptr1->next;
      } else {
        ptr->next = ptr2;
        ptr2 = ptr2->next;
      }
      ptr = ptr->next;
    }
    if (ptr1 != nullptr) {
      ptr->next = ptr1;
    }
    if (ptr2 != nullptr) {
      ptr->next = ptr2;
    }
    return head->next;
  }
};

int main() {
  ListNode n1{1};
  ListNode n2{2};
  ListNode n4{4};
  n1.next = &n2;
  n2.next = &n4;

  ListNode b1{1};
  ListNode b3{3};
  ListNode b4{4};
  b1.next = &b3;
  b3.next = &b4;

  Solution so;
  so.print(so.mergeTwoLists(&n1, &b1));
}
