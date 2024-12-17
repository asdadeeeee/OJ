#include <iostream>
#include <memory>
#include <unordered_map>
using namespace std;

class LRUNode {
public:
  int k;
  int v;
  LRUNode *next;
  LRUNode *prev;
  LRUNode(int key, int value) : k(key), v(value) {
    next = nullptr;
    prev = nullptr;
  }
  LRUNode() : k(0), v(0), prev(nullptr), next(nullptr) {}
};

// class LRUList {
// public:
//   LRUNode *head;
//   LRUNode *tail;
//   int cur_size;

//   LRUList() {
//     head = new LRUNode(0, 0);
//     tail = new LRUNode(0, 0);
//     head->next = tail;
//     tail->prev = head;
//     cur_size = 0;
//   }

//   void AddNode(LRUNode *node) {
//     node->prev = tail->prev;
//     node->next = tail;
//     tail->prev->next = node;
//     tail->prev = node;
//     cur_size++;
//   }

//   void DeleteNode(LRUNode *node) {
//     node->prev->next = node->next;
//     node->next->prev = node->prev;
//     cur_size--;
//   }

//   LRUNode *DeleteFirst() {
//     auto temp = head->next;
//     head->next->next->prev = head;
//     head->next = head->next->next;
//     cur_size--;
//     return temp;
//   }

//   int getSize() { return cur_size; }
// };
class LRUCache {

public:
  unordered_map<int, LRUNode *> nodes;
  LRUNode *head;
  LRUNode *tail;
  int size;
  int cap;
  LRUCache(int capacity) : cap(capacity) {
    head = new LRUNode(0, 0);
    tail = new LRUNode(0, 0);
    head->next = tail;
    tail->prev = head;
    size = 0;
  }

  int get(int key) {
    auto iter = nodes.find(key);
    if (iter == nodes.end()) {
      return -1;
    }
    auto ptr = iter->second;
    ptr->prev->next = ptr->next;
    ptr->next->prev = ptr->prev;
    tail->prev->next = ptr;
    ptr->prev = tail->prev;
    ptr->next = tail;
    tail->prev = ptr;
    return ptr->v;
  }

  void put(int key, int value) {
    auto old_iter = nodes.find(key);
    if (old_iter != nodes.end()) {
      auto ptr = old_iter->second;
      ptr->v = value;
      ptr->prev->next = ptr->next;
      ptr->next->prev = ptr->prev;
      ptr->prev = tail->prev;
      ptr->next = tail;
      tail->prev->next = ptr;
      tail->prev = ptr;
      return;
    }
    auto node = new LRUNode(key, value);
    nodes.insert({key, node});
    node->prev = tail->prev;
    node->next = tail;
    tail->prev->next = node;
    tail->prev = node;
    size++;
    if (size > cap) {
      auto ptr = head->next;
      head->next->next->prev = head;
      head->next = head->next->next;
      size--;
      nodes.erase(ptr->k);
      delete ptr;
    }
  }
};

int main() {
  LRUCache cache(2);
  cache.put(2, 1);
  cache.put(2, 2);
  int res1 = cache.get(2);
  cout << res1;
  cache.put(1, 1);
  cache.put(4, 1);
  int res2 = cache.get(2);
  cout << res2;
}
