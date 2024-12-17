#include <iostream>
#include <memory>
#include <unordered_map>
using namespace std;

class LRUNode {
public:
  int k;
  int v;
  shared_ptr<LRUNode> next;
  shared_ptr<LRUNode> prev;
  LRUNode(int key, int value) : k(key), v(value) {
    next = nullptr;
    prev = nullptr;
  }
};

class LRUList {
public:
  shared_ptr<LRUNode> head;
  shared_ptr<LRUNode> tail;
  int cur_size;

  LRUList() {
    head = std::make_shared<LRUNode>(0, 0);
    tail = std::make_shared<LRUNode>(0, 0);
    head->next = tail;
    tail->prev = head;
    cur_size = 0;
  }

  void AddNode(shared_ptr<LRUNode> node) {
    auto temp = std::move(node);
    temp->prev = tail->prev;
    temp->next = tail;
    tail->prev->next = temp;
    tail->prev = temp;
    cur_size++;
  }

  void DeleteNode(shared_ptr<LRUNode> node) {
    auto temp = std::move(node);
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    cur_size--;
  }

  shared_ptr<LRUNode> DeleteFirst() {
    auto temp = head->next;
    head->next->next->prev = head;
    head->next = head->next->next;
    cur_size--;
    return temp;
  }

  int getSize() { return cur_size; }
};
class LRUCache {

public:
  unordered_map<int, shared_ptr<LRUNode>> nodes;
  shared_ptr<LRUList> lru_list;
  int k;
  LRUCache(int capacity) : k(capacity) { lru_list = make_shared<LRUList>(); }

  void touch(shared_ptr<LRUNode> node) {
    lru_list->DeleteNode(node);
    lru_list->AddNode(node);
  }

  int get(int key) {
    auto iter = nodes.find(key);
    if (iter == nodes.end()) {
      return -1;
    }
    touch(iter->second);
    return iter->second->v;
  }

  void put(int key, int value) {
    auto old_iter = nodes.find(key);
    if (old_iter != nodes.end()) {
      lru_list->DeleteNode(old_iter->second);
      nodes.erase(old_iter);
    }
    auto node = make_shared<LRUNode>(key, value);
    lru_list->AddNode(node);
    nodes.insert({key, node});
    if (lru_list->getSize() > k) {
      auto temp = lru_list->DeleteFirst();
      nodes.erase(temp->k);
    }
  }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */