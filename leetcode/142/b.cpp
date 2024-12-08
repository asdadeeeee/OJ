#include <iostream>
#include <map>
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
  ListNode *detectCycle(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != nullptr) {
      slow = slow->next;
      if (fast->next == nullptr) {
        return nullptr;
      }
      fast = fast->next->next;
      if (fast == slow) {
        ListNode *anchor = head;
        while (anchor != slow) {
          anchor = anchor->next;
          slow = slow->next;
        }
        return anchor;
      }
    }
    return nullptr;
  }
};