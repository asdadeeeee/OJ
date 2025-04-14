
#include <cstring>
#include <iostream>
#include <memory>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
public:
  inline bool conn(const string &s1, const string &s2) {
    int temp = 0;
    int n = s1.size();
    int m = s2.size();
    if (n != m) {
      return false;
    }
    for (int i = 0; i < n; i++) {
      if (s1[i] != s2[i]) {
        temp++;
      }
      if (temp == 2) {
        return false;
      }
    }
    return true;
  }
  int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
    N = wordList.size();
    connect.resize(N, vector<bool>(N, false));
    visit.resize(N, false);
    finish.resize(N, false);
    bool inlist = false;
    queue<int> q;
    for (int i = 0; i < N; i++) {
      if (wordList[i] == endWord) {
        finish[i] = true;
        inlist = true;
      }
      for (int j = i + 1; j < N; j++) {
        if (conn(wordList[i], wordList[j])) {
          connect[i][j] = true;
          connect[j][i] = true;
        } else {
          connect[i][j] = false;
          connect[j][i] = false;
        }
      }
    }
    if (!inlist) {
      return 0;
    }
    int path = 0;
    q.push(-1);

    while (!q.empty()) {
      int n = q.size();
      path++;
      for (int i = 0; i < n; i++) {
        int cur = q.front();
        q.pop();
        if (cur == -1) {

          for (int j = 0; j < N; j++) {
            if (conn(beginWord, wordList[j])) {
              q.push(j);
              visit[j] = true;
            }
          }
        } else {
          if (finish[cur]) {
            return path;
          }
          for (int j = 0; j < N; j++) {
            if (cur != j && !visit[j] && connect[cur][j]) {
              q.push(j);
              visit[j] = true;
            }
          }
        }
      }
    }
    return 0;
  }
  int N;
  vector<vector<bool>> connect;
  vector<bool> visit;
  vector<bool> finish;
};