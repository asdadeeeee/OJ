#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;
int N;
map<string, vector<string>> childs;
map<string, int> depths;
vector<string> roots;
set<string> ans;
int main() {
  cin >> N;
  queue<string> q;
  string scur;
  string spre;

  for (int i = 0; i < N; i++) {
    cin >> scur >> spre;
    if (spre == "NA") {
      roots.emplace_back(scur);
    } else {
      childs[spre].emplace_back(scur);
    }
  }
  int max_depth = -1;
  for (const auto &root : roots) {
    int depth = -1;
    max_depth = max(depth, max_depth);
    while (!q.empty()) {
      q.pop();
    }
    q.push(root);
    while (!q.empty()) {

      int n = q.size();
      if (n > 0) {
        depth++;
        max_depth = max(depth, max_depth);
      }
      for (int i = 0; i < n; i++) {
        string cur = q.front();
        q.pop();
        depths[cur] = depth;
        for (const auto &child : childs[cur]) {
          q.push(child);
        }
      }
    }
  }
  for (const auto &p : depths) {
    // cout<<p.first<<endl;
    if (p.second == max_depth) {
      ans.insert(p.first);
    }
  }
  for (const auto &s : ans) {
    cout << s << " ";
  }
  return 0;
}