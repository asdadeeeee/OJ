#include <functional>
#include <iostream>
#include <mutex>
#include <optional>
#include <shared_mutex>
#include <stdexcept>
#include <string>
#include <thread>
#include <unordered_map>
#include <vector>
template <typename Key, typename Value, typename Hash = std::hash<Key>>
class ConcurrentKeyValueStore {
private:
  struct Shard {
    std::unordered_map<Key, Value, Hash> store;
    mutable std::shared_mutex mutex;
  };

  std::vector<Shard> shards_;
  size_t num_shards_;
  Hash hasher_;

  size_t get_shard_index(const Key &key) const {
    return hasher_(key) % num_shards_;
  }

public:
  explicit ConcurrentKeyValueStore(size_t num_shards = 16)
      : shards_(num_shards), num_shards_(num_shards), hasher_(Hash()) {
    // Initialize vector with num_shards elements in initializer list
  }

  void put(const Key &key, const Value &value) {
    size_t shard_index = get_shard_index(key);
    auto &shard = shards_[shard_index];
    std::unique_lock<std::shared_mutex> lock(shard.mutex);
    shard.store[key] = value;
  }

  std::optional<Value> get(const Key &key) const {
    size_t shard_index = get_shard_index(key);
    const auto &shard = shards_[shard_index];
    std::shared_lock<std::shared_mutex> lock(shard.mutex);
    auto it = shard.store.find(key);
    if (it != shard.store.end()) {
      return it->second;
    }
    return std::nullopt;
  }

  bool remove(const Key &key) {
    size_t shard_index = get_shard_index(key);
    auto &shard = shards_[shard_index];
    std::unique_lock<std::shared_mutex> lock(shard.mutex);
    return shard.store.erase(key) > 0;
  }

  bool contains(const Key &key) const {
    size_t shard_index = get_shard_index(key);
    const auto &shard = shards_[shard_index];
    std::shared_lock<std::shared_mutex> lock(shard.mutex);
    return shard.store.find(key) != shard.store.end();
  }

  size_t size() const {
    size_t total = 0;
    for (const auto &shard : shards_) {
      std::shared_lock<std::shared_mutex> lock(shard.mutex);
      total += shard.store.size();
    }
    return total;
  }

  void clear() {
    for (auto &shard : shards_) {
      std::unique_lock<std::shared_mutex> lock(shard.mutex);
      shard.store.clear();
    }
  }

  void resize(size_t new_num_shards) {
    std::vector<Shard> new_shards(new_num_shards);
    std::vector<std::unique_lock<std::shared_mutex>> locks;
    for (auto &shard : shards_) {
      locks.emplace_back(shard.mutex);
    }
    for (const auto &shard : shards_) {
      for (const auto &[key, value] : shard.store) {
        size_t new_index = hasher_(key) % new_num_shards;
        new_shards[new_index].store[key] = value;
      }
    }
    shards_ = std::move(new_shards);
    num_shards_ = new_num_shards;
  }
};

int main() {
  // 创建一个支持字符串键和整数值的并发键值存储
  ConcurrentKeyValueStore<std::string, int> kv_store(4);

  // 并发写入
  auto writer = [&kv_store](int start, int end) {
    for (int i = start; i < end; ++i) {
      kv_store.put("key" + std::to_string(i), i);
    }
  };

  // 并发读取
  auto reader = [&kv_store](int start, int end) {
    for (int i = start; i < end; ++i) {
      auto value = kv_store.get("key" + std::to_string(i));
      if (value) {
        std::cout << "key" << i << ": " << *value << std::endl;
      }
    }
  };

  // 启动多个线程进行写入
  std::vector<std::thread> threads;
  threads.emplace_back(writer, 0, 1000);
  threads.emplace_back(writer, 1000, 2000);
  threads.emplace_back(writer, 2000, 3000);

  // 启动读取线程
  threads.emplace_back(reader, 0, 1000);

  // 等待所有线程完成
  for (auto &t : threads) {
    t.join();
  }

  // 输出总键值对数量
  std::cout << "Total size: " << kv_store.size() << std::endl;

  // 测试删除
  // kv_store.remove("key1");
  // std::cout << "Contains key1: " << kv_store.contains("key1") << std::endl;

  // // 测试动态扩展
  kv_store.resize(8);
  std::cout << "After resize, total size: " << kv_store.size() << std::endl;

  return 0;
}