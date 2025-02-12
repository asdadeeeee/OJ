
#include <cstddef>
#include <iostream>
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
  ListNode *rev(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }
    ListNode *last = rev(head->next);
    head->next->next = head;
    head->next = nullptr;
    return last;
  }
  ListNode *reverseList(ListNode *head) { return rev(head); }
};