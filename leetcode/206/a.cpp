
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
    if (head->next == nullptr) {
      return head;
    }
    head->next = rev(head->next);
    ListNode *next = head->next;
    ListNode *tail = head;
    while (tail->next != nullptr) {
      tail = tail->next;
    }
    tail->next = head;
    head->next = nullptr;
    return next;
  }
  ListNode *reverseList(ListNode *head) {
    if (head == nullptr) {
      return nullptr;
    }
    return rev(head);
  }
};