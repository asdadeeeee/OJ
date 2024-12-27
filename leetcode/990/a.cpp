#include <cstring>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class UF {
public:
  UF(int n) {
    cnt = n;
    for (int i = 0; i < n; i++) {
      char c = 'a' + i;
      parent[c] = c;
    }
  }

  char findparent(char c) {
    while (parent[c] != c) {
      parent[c] = findparent(parent[c]);
      c = parent[c];
    }
    return parent[c];
  }

  bool connected(char c, char d) { return findparent(c) == findparent(d); }

  void uni(char c, char d) {
    if (c == d) {
      return;
    }
    char rc = findparent(c);
    char rd = findparent(d);
    if (rc != rd) {
      parent[rc] = rd;
    }
    cnt--;
  }

  int cnt = 0;
  unordered_map<char, char> parent;
};
class Solution {
public:
  bool equationsPossible(vector<string> &equations) {
    UF uf(26);
    for (auto &e : equations) {
      if (e[1] == '!') {
        une.emplace_back(e[0], e[3]);
      } else {
        uf.uni(e[0], e[3]);
      }
    }
    for (auto &u : une) {
      if (uf.connected(u.first, u.second)) {
        return false;
      }
    }
    return true;
  }

  vector<pair<char, char>> une;
};