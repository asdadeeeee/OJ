#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
int N;
vector<vector<int>> g;
vector<bool> visit;
vector<int> dist;
vector<int> pre;
vector<int> ans;
const int inf = 0x3f3f3f3f;
int beginidx = 0;
int endidx = 0;
int getidx(char c) { return c - 'a'; }
void serial(const string &input) {
  char pc = input[0];
  char qc = input[2];
  int p = getidx(pc);
  int q = getidx(qc);
  string valuestr = input.substr(4, input.size() - 4);
  int value = stoi(valuestr);
  g[p][q] = min(g[p][q], value);
  g[q][p] = min(g[q][p], value);
}
void print() {
  int tempend = endidx;
  ans.insert(ans.begin(), tempend);
  while (pre[tempend] != tempend) {
    tempend = pre[tempend];
    ans.insert(ans.begin(), tempend);
  }
  for (auto a : ans) {
    char c = a + 'a';
    cout << c << " ";
  }
}
int main() {
  cin >> N;
  cin.ignore();
  g.resize(N, vector<int>(N, inf));
  for (int i = 0; i < N; i++) {
    g[i][i] = 0;
  }
  visit.resize(N, false);
  dist.resize(N, inf);
  pre.resize(N, 0);
  string line;
  getline(cin, line);
  stringstream ss(line);
  string start, end;
  ss >> start >> end;
  char bc = start[0];
  char ec = end[0];
  beginidx = getidx(bc);
  endidx = getidx(ec);
  while (true) {
    getline(cin, line);
    if (line == "0000") {
      break;
    }
    stringstream ss_time(line);
    char pc, qc;
    int value;
    ss_time >> pc >> qc >> value;
    int p = getidx(pc);
    int q = getidx(qc);
    g[p][q] = min(g[p][q], value);
    // g[q][p] = min(g[q][p], value);
  }
  dist[beginidx] = 0;
  visit[beginidx] = true;
  pre[beginidx] = beginidx;
  for (int i = 0; i < N; i++) {
    if (g[beginidx][i] < dist[i]) {
      dist[i] = g[beginidx][i];
      pre[i] = beginidx;
    }
  }
  for (int i = 0; i < N - 1; i++) {
    int cur = -1;
    for (int j = 0; j < N; j++) {
      if (!visit[j] && (cur == -1 || dist[j] < dist[cur])) {
        cur = j;
      }
    }
    visit[cur] = true;
    for (int j = 0; j < N; j++) {
      if (!visit[j]) {
        if (dist[cur] + g[cur][j] < dist[j]) {
          dist[j] = dist[cur] + g[cur][j];
          pre[j] = cur;
        }
      }
    }
  }
  print();
  return 0;
}
