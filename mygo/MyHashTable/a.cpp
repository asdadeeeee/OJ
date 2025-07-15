#include <cassert>
#include <chrono> // 添加 chrono 库
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
using namespace chrono; // 使用 chrono 命名空间
class Node {
  friend class MyHashTable;

public:
  Node() {
    k = 0;
    v = 0;
    status = 0;
  }
  Node(int k, int v) : k(k), v(v) { status = 1; }

private:
  int k;
  int v;
  int status;
};
class MyHashTable {
public:
  MyHashTable(int c) {
    cap = c;
    vec.resize(cap);
  }
  inline int get(int key) {
    int index = 0;
    if (exist(key, index)) {
      return vec[index].v;
    }
    return -1;
  };
  void remove(int key) {
    int index = 0;
    if (exist(key, index)) {
      vec[index].status = 2;
    }
    return;
  }
  inline bool put(int key, int value) {
    int idx = Hash(key);
    int init = idx;

    while (vec[idx].status == 1 || vec[idx].status == 2) {
      if (vec[idx].k == key || vec[idx].status == 2) {
        break;
      }
      int next = (idx + 1) % cap;
      if (next == init) {
        return false;
      }
      idx = next;
    }
    vec[idx].k = key;
    vec[idx].v = value;
    vec[idx].status = 1;
    return true;
  }

private:
  inline int Hash(int k) { return k % cap; }

  inline bool exist(int key, int &index) {
    int idx = Hash(key);
    int init = idx;
    while (vec[idx].status == 1 || vec[idx].status == 2) {
      if (vec[idx].k == key && vec[idx].status == 1) {
        index = idx;
        return true;
      }
      int next = (idx + 1) % cap;
      if (next == init) {
        break;
      }
      idx = next;
    }
    return false;
  }

private:
  int cap;
  vector<Node> vec;
};
int main() {
  MyHashTable map(10);
  // 插入键值对并验证
  assert(map.put(1, 10));
  assert(map.put(11, 110));
  assert(map.get(1) == 10);
  assert(map.get(11) == 110);

  assert(map.put(2, 20));
  assert(map.put(3, 30));
  assert(map.get(2) == 20);
  assert(map.get(3) == 30);

  assert(map.put(2, 200));
  assert(map.put(3, 300));
  assert(map.get(2) == 200);
  assert(map.get(3) == 300);

  assert(map.put(12, 1200));
  assert(map.put(14, 1400));
  assert(map.get(12) == 1200);
  assert(map.get(14) == 1400);
  assert(map.get(13) == -1);

  assert(map.put(13, 1300));
  assert(map.put(15, 1500));
  assert(map.get(13) == 1300);
  assert(map.get(15) == 1500);

  assert(map.put(13, 13000));
  assert(map.put(15, 15000));
  assert(map.get(13) == 13000);
  assert(map.get(15) == 15000);

  assert(map.put(18, 1800));
  assert(map.put(17, 1700));
  assert(map.get(18) == 1800);
  assert(map.get(17) == 1700);
  map.remove(18);
  map.remove(17);
  assert(map.put(8, 800));
  assert(map.put(7, 700));
  assert((map.get(8) == 800));
  assert((map.get(7) == 700));

  // 验证之前插入的键值对是否仍然正确
  assert(!(map.get(18) == 1800));
  assert(!(map.get(17) == 1700));
  assert(map.get(1) == 10);
  assert(map.get(11) == 110);
  assert(map.get(2) == 200);
  assert(map.get(3) == 300);
  assert(map.get(12) == 1200);
  assert(map.get(14) == 1400);
  assert(map.get(13) == 13000);
  assert(map.get(15) == 15000);

  cout << "All tests passed!" << endl;

  int sz = 1 << 20;
  srand(time(nullptr)); // 设置随机种子

  MyHashTable t(sz);

  unordered_map<int, int> ut;
  int case_size = sz;
  vector<pair<int, int>> test_cases;
  for (int i = 0; i < case_size; i++) {
    int k = rand() % case_size;
    int v = rand();
    test_cases.push_back({k, v});
  }

  for (auto &p : test_cases) {
    int k = p.first;
    int v = p.second;
    assert(t.put(k, v));
    ut[k] = v;
  }

  // 测试自定义 HashTable 的读取性能
  auto start = high_resolution_clock::now();
  for (auto &p : test_cases) {
    int k = p.first;
    int v = ut[k];
    int val = t.get(k);
    assert(val == v); // 验证结果
  }
  auto end = high_resolution_clock::now();
  auto custom_duration = duration_cast<milliseconds>(end - start).count();
  cout << "Custom HashTable read time: " << custom_duration << " ms" << endl;

  // 测试 std::unordered_map 的读取性能
  start = high_resolution_clock::now();
  for (auto &p : test_cases) {
    int k = p.first;
    int v = p.second;
    int val = ut[k];
    // assert(val == v); // 验证结果
  }
  end = high_resolution_clock::now();
  auto std_duration = duration_cast<milliseconds>(end - start).count();
  cout << "std::unordered_map read time: " << std_duration << " ms" << endl;
}