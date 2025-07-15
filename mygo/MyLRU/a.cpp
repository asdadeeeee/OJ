#include <iostream>
#include <unordered_map>
using namespace std;
class LRUNode {
public:
  friend class LRUList;
  LRUNode() {
    k = 0;
    v = 0;
    next = nullptr;
    pre = nullptr;
  }
  LRUNode(int key, int value) : k(key), v(value) {
    next = nullptr;
    pre = nullptr;
  }
  int GetKey() { return k; }
  void setValue(int value) { v = value; }
  int getValue() { return v; }

private:
  int k;
  int v;
  LRUNode *next;
  LRUNode *pre;
};
class LRUList {
public:
  LRUList() {
    cur_size = 0;
    head = new LRUNode();
    tail = new LRUNode();
    head->next = tail;
    tail->pre = head;
  }
  int GetSize() { return cur_size; }
  void AddNode(LRUNode *node) {
    LRUNode *pre = tail->pre;
    node->pre = pre;
    node->next = tail;
    pre->next = node;
    tail->pre = node;
    cur_size++;
  }
  void DeleteNode(LRUNode *node) {
    LRUNode *pre = node->pre;
    LRUNode *next = node->next;
    pre->next = next;
    next->pre = pre;
    cur_size--;
  }
  LRUNode *Evict() {
    LRUNode *temp = head->next;
    LRUNode *next = head->next->next;
    next->pre = head;
    head->next = next;
    cur_size--;
    return temp;
  }
  void touch(LRUNode *node) {
    DeleteNode(node);
    AddNode(node);
  }

private:
  int cur_size;
  LRUNode *head;
  LRUNode *tail;
};
class MyLRUCache {
public:
  MyLRUCache(int c) { cap = c; }
  void put(int key, int value) {
    if (m.count(key) != 0) {
      m[key]->setValue(value);
      list.touch(m[key]);
    } else {
      if (list.GetSize() == cap) {
        LRUNode *victim = list.Evict();
        m.erase(victim->GetKey());
        delete victim;
        victim = nullptr;
      }
      LRUNode *node = new LRUNode(key, value);
      list.AddNode(node);
      m[key] = node;
    }
  }
  int get(int key) {
    if (m.count(key) != 0) {
      list.touch(m[key]);
      return m[key]->getValue();
    } else {
      return -1;
    }
  }

private:
  int cap;
  LRUList list;
  unordered_map<int, LRUNode *> m;
};