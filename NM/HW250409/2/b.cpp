#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<vector<int>> grid(N, vector<int>(N, INT_MAX));
  char start, end;
  cin >> start >> end;
  int start_index = start - 'a', end_index = end - 'a';
  while (1) {
    char A, B;
    string tmp;
    int distance;
    cin >> A;
    tmp = A;
    if (tmp == "0")
      break;
    // cout<<tmp<<endl;
    cin >> B >> distance;
    grid[A - 'a'][B - 'a'] = distance;
  }
  vector<int> visited(N, 0);
  vector<int> distance_grid(N, INT_MAX);
  distance_grid[start_index] = 0;
  visited[start_index] = 0;
  vector<int> result(N, -1);
  unordered_map<int, int> um;
  for (int i = 0; i < N; i++) {
    int min_val = INT_MAX;
    int cur = start_index;
    for (int v = 0; v < N; v++) {
      if (!visited[v] && distance_grid[v] < min_val) {
        cur = v;
        min_val = distance_grid[v];
      }
    }
    visited[cur] = 1;
    for (int v = 0; v < N; v++) {
      if (!visited[v] && grid[cur][v] != INT_MAX &&
          distance_grid[cur] + grid[cur][v] < distance_grid[v]) {
        distance_grid[v] = distance_grid[cur] + grid[cur][v];
        result[v] = cur;
      }
    }
  }

  vector<char> path;
  for (int at = end_index; at != -1; at = result[at]) {
    path.push_back(at + 'a');
  }
  reverse(path.begin(), path.end());

  // 输出路径
  for (int i = 0; i < path.size(); i++) {
    if (i > 0)
      cout << " ";
    cout << path[i];
  }
}