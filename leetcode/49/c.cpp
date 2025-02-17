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
      string temp = str;
      sort(temp.begin(), temp.end());
      auto index_it = ans_index.find(temp);
      if (index_it != ans_index.end()) {
        ans[index_it->second].emplace_back(str);
      } else {
        vector<string> new_group;
        new_group.emplace_back(str);
        ans.emplace_back(new_group);
        ans_index[temp] = ans.size() - 1;
      }
    }
    return ans;
  }
};
