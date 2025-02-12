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
  ListNode *rev(ListNode *head, int deep, int &cur) {
    if (head == nullptr || head->next == nullptr || cur == deep) {
      return head;
    }
    cur++;
    ListNode *last = rev(head->next, deep, cur);
    head->next->next = head;
    head->next = nullptr;
    return last;
  }
  ListNode *reverseBetween(ListNode *head, int left, int right) {
    int L = left - 1;
    int R = right + 1;
    ListNode *left_ptr = head;
    ListNode *right_ptr = head;
    if (L == 0) {
      left_ptr = nullptr;
    }
    if (R == 0) {
      right_ptr = nullptr;
    }
    for (int i = 1; i < L; i++) {
      left_ptr = left_ptr->next;
    }
    for (int i = 1; i < R; i++) {
      right_ptr = right_ptr->next;
    }
    int deep = right - left;
    ListNode *left_head = head;

    for (int i = 1; i < left; i++) {
      left_head = left_head->next;
    }
    int cur = 0;
    ListNode *ll = rev(left_head, deep, cur);
    ListNode *right_head = ll;
    for (int i = 0; i < deep; i++) {
      right_head = right_head->next;
    }
    if (left_ptr != nullptr) {
      left_ptr->next = ll;
    }
    right_head->next = right_ptr;
    if (left_ptr == nullptr) {
      return ll;
    }
    return head;
  }
};