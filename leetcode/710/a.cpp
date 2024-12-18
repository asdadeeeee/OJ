#include <cstdlib>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;
class Solution {
public:
  Solution(int n, vector<int> &blacklist) {
    sz = n - blacklist.size();
    int last = n - 1;
    for (auto b : blacklist) {
      index[b] = -1;
    }
    for (auto b : blacklist) {
      if (b >= sz) {
        continue;
      }
      while (index.count(last)) {
        last--;
      }
      index[b] = last;
      last--;
    }
  }

  int pick() {
    int k = rand() % sz;
    if (index.count(k) != 0) {
      return index[k];
    }
    return k;
  }

  unordered_map<int, int> index;
  int sz;
};

int main() {
  vector<int> black{2, 3, 5};
  Solution sol(7, black);
  int a = sol.pick();
  cout << a;
  a = sol.pick();
  cout << a;
  a = sol.pick();
  cout << a;
}
