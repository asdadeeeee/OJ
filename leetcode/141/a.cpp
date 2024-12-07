#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  bool hasCycle(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return false;
    }
    ListNode *ptr1 = head;
    ListNode *ptr2 = head->next;
    int pos = -1;
    bool flag = false;

    while (ptr1 != nullptr && ptr2 != nullptr) {
      if (ptr1 == ptr2) {
        flag = true;
        break;
      }
      if (ptr1->next != nullptr) {
        ptr1 = ptr1->next;
      } else {
        flag = false;
        break;
      }
      if (ptr2->next != nullptr) {
        ptr2 = ptr2->next;
        if (ptr2->next != nullptr) {
          ptr2 = ptr2->next;
        } else {
          flag = false;
          break;
        }
      } else {
        flag = false;
        break;
      }
    }
    return flag;
  }
};