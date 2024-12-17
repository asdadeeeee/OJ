#include <iostream>
#include <memory>
#include <set>
#include <unordered_map>
#include <utility>
using namespace std;

class LFUNode {
public:
  int k, v;
  int timestamp;
  int count;
  LFUNode(int k, int v, int t) : k(k), v(v), timestamp(t) { count = 0; }
  LFUNode(){};
};
class comp {
public:
  bool operator()(const shared_ptr<LFUNode> &s1,
                  const shared_ptr<LFUNode> &s2) const {
    return s1->count != s2->count ? s1->count < s2->count
                                  : s1->timestamp < s2->timestamp;
  }
};
class LFUCache {
public:
  set<shared_ptr<LFUNode>, comp> nodes;
  unordered_map<int, shared_ptr<LFUNode>> cache;
  int cap;
  int time;

public:
  LFUCache(int capacity) {
    cap = capacity;
    time = 0;
  }

  int get(int key) {
    auto iter = cache.find(key);
    if (iter == cache.end()) {
      return -1;
    }
    auto node = iter->second;
    nodes.erase(node);
    node->timestamp = ++time;
    node->count++;
    nodes.insert(node);
    return node->v;
  }

  void put(int key, int value) {
    auto iter = cache.find(key);
    if (iter != cache.end()) {
      auto node = iter->second;
      nodes.erase(node);
      node->timestamp = ++time;
      node->count++;
      node->v = value;
      nodes.insert(node);
      return;
    }
    if (cache.size() == cap) {
      auto temp = nodes.begin();
      cache.erase((*temp)->k);
      nodes.erase(temp);
    }
    auto node = make_shared<LFUNode>(key, value, ++time);
    node->count = 1;
    nodes.insert(node);
    cache.insert({key, node});
  }
};

int main() {
  LFUCache cache(2);
  cache.put(2, 1);
  cache.put(2, 2);
  int res1 = cache.get(2);
  cout << res1;
  cache.put(1, 1);
  cache.put(4, 1);
  int res2 = cache.get(2);
  cout << res2;
}
