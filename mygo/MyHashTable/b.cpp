#include <cassert>
#include <chrono> // 添加 chrono 库
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
using namespace chrono; // 使用 chrono 命名空间

class HashTable {

  vector<pair<int, int>> kv_;
  // 0 for not used ,1 for using , 2 for used
  vector<int> used_;
  int sz_;

public:
  HashTable(int sz)
      : kv_(vector<pair<int, int>>(sz)), used_(vector<int>(sz, 0)), sz_(sz){};

  void put(int k, int v) {
    int h = k % sz_;
    auto p = kv_[h];
    while (used_[h] == 1 && p.first != k) {
      h = (h + 1) % sz_;
      p = kv_[h];
    }
    kv_[h] = {k, v};
    used_[h] = 1;
  }

  bool exist(int k) {
    auto h = k % sz_;
    auto p = kv_[h];
    while (used_[h] == 2 || (used_[h] == 1 && p.first != k)) {
      h = k % sz_;
      p = kv_[h];
    }
    if (used_[h] == 1 && p.first == k) {
      return true;
    }
    return false;
  }
  void del(int k) {
    auto h = k % sz_;
    auto p = kv_[h];
    while (used_[h] == 2 || (used_[h] == 1 && p.first != k)) {
      h = k % sz_;
      p = kv_[h];
    }
    if (used_[h] == 1 && p.first == k) {
      used_[h] = 2;
    }
  }
  int get(int k) {
    auto h = k % sz_;
    auto p = kv_[h];
    while (used_[h] == 2 || (used_[h] == 1 && p.first != k)) {
      h = k % sz_;
      p = kv_[h];
    }
    if (used_[h] == 1 && p.first == k) {
      return p.second;
    }
    return -1;
  }
};
int main() {
  int sz = 1 << 20;
  srand(time(nullptr)); // 设置随机种子

  HashTable t(sz);

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
    t.put(k, v);
    ut[k] = v;
  }

  // 测试自定义 HashTable 的读取性能
  auto start = high_resolution_clock::now();
  for (auto &p : test_cases) {
    int k = p.first;
    int v = p.second;
    int val = t.get(k);
    // assert(val == v || val == -1); // 验证结果
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