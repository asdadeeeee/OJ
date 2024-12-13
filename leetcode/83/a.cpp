#include <iostream>
#include <queue>
#include <set>
#include <vector>
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
  ListNode *deleteDuplicates(ListNode *head) {
    if (head == nullptr) {
      return nullptr;
    }
    ListNode *slow = head;
    ListNode *fast = head->next;
    while (fast != nullptr) {
      while (slow->val == fast->val) {
        slow->next = fast->next;
        fast = fast->next;
        if (fast == nullptr) {
          return head;
        }
      }
      slow = slow->next;
      fast = fast->next;
    }
    return head;
  }
};
