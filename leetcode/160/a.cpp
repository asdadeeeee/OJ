#include <iostream>
#include <set>
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
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *ptr1 = headA;
    ListNode *ptr2 = headB;
    while (ptr1 != nullptr || ptr2 != nullptr) {
      if (ptr1 != nullptr) {
        if (nodes.find(ptr1) == nodes.end()) {
          nodes.insert(ptr1);
        } else {
          return ptr1;
        }
        ptr1 = ptr1->next;
      }
      if (ptr2 != nullptr) {
        if (nodes.find(ptr2) == nodes.end()) {
          nodes.insert(ptr2);
        } else {
          return ptr2;
        }
        ptr2 = ptr2->next;
      }
    }
    return nullptr;
  }

  set<ListNode *> nodes;
};
