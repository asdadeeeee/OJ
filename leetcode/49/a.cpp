#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    vector<vector<string>> ans;
    for (auto &str : strs) {
      unordered_map<char, int> cur;
      for (char c : str) {
        cur[c]++;
      }
      bool find = false;
      for (auto &group : ans) {
        unordered_map<char, int> g;
        for (char c : group[0]) {
          g[c]++;
        }
        bool match = true;
        for (auto it : g) {
          if (cur[it.first] != it.second) {
            match = false;
            break;
          }
        }
        if (match) {
          for (auto it : cur) {
            if (g[it.first] != it.second) {
              match = false;
              break;
            }
          }
        }
        if (match) {
          find = true;
          group.emplace_back(str);
          break;
        }
      }
      if (!find) {
        vector<string> new_group;
        new_group.emplace_back(str);
        ans.emplace_back(new_group);
      }
    }
    return ans;
  }
};