#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
  bool canConstruct(string ransomNote, string magazine) {
    unordered_map<char, int> target;
    unordered_map<char, int> mag;
    for (char c : magazine) {
      mag[c]++;
    }
    for (char c : ransomNote) {
      target[c]++;
    }
    for (auto it : target) {
      if (mag[it.first] < it.second) {
        return false;
      }
    }
    return true;
  }
};