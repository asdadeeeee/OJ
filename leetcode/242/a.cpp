#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
  bool isAnagram(string s, string t) {
    unordered_map<char, int> target;
    unordered_map<char, int> cur;
    for (char c : s) {
      target[c]++;
    }
    for (char c : t) {
      cur[c]++;
    }
    for (auto it : target) {
      if (cur[it.first] != it.second) {
        return false;
      }
    }
    for (auto it : cur) {
      if (target[it.first] != it.second) {
        return false;
      }
    }
    return true;
  }
};