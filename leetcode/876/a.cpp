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
  ListNode *middleNode(ListNode *head) {
    if (head == nullptr) {
      return nullptr;
    }
    ListNode *slow = head;
    ListNode *fast = head->next;
    while (fast != nullptr) {
      slow = slow->next;
      if (fast->next != nullptr) {
        fast = fast->next->next;
      } else {
        break;
      }
    }
    return slow;
  }
};