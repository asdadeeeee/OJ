#include <algorithm>
#include <iostream>
#include <vector>

#include <cstring>
#include <numeric>
#include <string>
using namespace std;

class Solution {
public:
  bool wordBreak(string s, vector<string> &wordDict) {
    int length = s.length();
    int n = wordDict.size();
    vector<bool> accept(length + 1, false);
    accept[0] = true;
    for (int i = 0; i < length; i++) {
      for (int j = 0; j < n; j++) {
        if (i + 1 >= wordDict[j].size()) {
          if (s.substr(i + 1 - wordDict[j].size(), wordDict[j].size()) ==
              wordDict[j]) {
            if (accept[i + 1 - wordDict[j].size()]) {
              accept[i + 1] = accept[i + 1 - wordDict[j].size()];
              break;
            }
          }
        }
      }
    }
    return accept[length];
  }
};