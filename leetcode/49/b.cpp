#include <algorithm>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    vector<vector<string>> ans;
    unordered_map<string, int> ans_index;
    for (auto &str : strs) {
      map<char, int> cur;
      for (char c : str) {
        cur[c]++;
      }
      string key;
      for (auto it : cur) {
        key = key + it.first + to_string(it.second);
      }
      auto index_iter = ans_index.find(key);
      if (index_iter != ans_index.end()) {
        ans[index_iter->second].emplace_back(str);
      } else {
        vector<string> new_group;
        new_group.emplace_back(str);
        ans.emplace_back(new_group);
        ans_index[key] = ans.size() - 1;
      }
    }
    return ans;
  }
};