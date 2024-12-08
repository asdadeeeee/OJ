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
    ListNode *ptr = head;
    while (ptr != nullptr) {
      if (step.find(ptr) == step.end()) {
        step.insert(ptr);
      } else {
        return ptr;
      }
      ptr = ptr->next;
    }
    return nullptr;
  }
  set<ListNode *> step;
};