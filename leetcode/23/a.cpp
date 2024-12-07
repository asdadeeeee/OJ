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
  struct cmpClass {
    // 操作符重载函数，必须是写()
    bool operator()(ListNode *&a, ListNode *&b) {
      // less,大顶堆
      return a->val > b->val;
    }
  };

public:
  void print(ListNode *list) {
    while (list != nullptr) {
      cout << list->val << " ";
      list = list->next;
    }
    cout << endl;
  }

  ListNode *mergeKLists(vector<ListNode *> &lists) {
    for (const auto &ptr : lists) {
      if (ptr != nullptr) {
        entries.emplace(ptr);
      }
    }

    ListNode *head = new ListNode;
    ListNode *temp_ptr = head;
    while (!entries.empty()) {
      auto next_node = entries.top();
      entries.pop();
      // auto p = new ListNode(next_node.val);
      temp_ptr->next = next_node;

      if (next_node->next != nullptr) {
        entries.emplace(next_node->next);
      }
      temp_ptr = temp_ptr->next;
    }
    return head->next;
  }

  priority_queue<ListNode *, vector<ListNode *>, cmpClass> entries;
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
  vector<ListNode *> vecs;
  vecs.emplace_back(&n1);
  vecs.emplace_back(&b1);
  so.print(so.mergeKLists(vecs));
}
