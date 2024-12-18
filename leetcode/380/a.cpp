#include <cstdlib>
#include <iostream>
#include <random>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
class RandomizedSet {
public:
  RandomizedSet() {}

  bool insert(int val) {
    if (index.find(val) != index.end()) {
      return false;
    }
    index[val] = sets.size();
    sets.push_back(val);
    return true;
  }

  bool remove(int val) {
    auto index_iter = index.find(val);
    if (index_iter == index.end()) {
      return false;
    }
    auto idx = index_iter->second;
    index.find(sets.back())->second = idx;
    index.erase(index_iter);
    swap(sets[idx], sets.back());
    sets.pop_back();
    return true;
  }

  int getRandom() { return sets[rand() % sets.size()]; }

  std::vector<int> sets;
  std::unordered_map<int, int> index;
};