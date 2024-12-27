#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold) {
    int inf = 0x3f3f3f3f;
    dist.resize(n, vector<int>(n, inf));
    for (auto &e : edges) {
      dist[e[0]][e[1]] = e[2];
      dist[e[1]][e[0]] = e[2];
    }

    vector<int> temp;
    temp.reserve(n);
    for (int i = 0; i < n; i++) {
      temp.emplace_back(i);
      dist[i][i] = 0;
    }
    // step.resize(n, temp);

    floyd(n, distanceThreshold);
    int min_size = inf;
    int ans = -1;
    vector<int> city_minl(n, 0);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (dist[i][j] <= distanceThreshold) {
          city_minl[i]++;
        }
      }
    }
    for (int i = 0; i < n; i++) {
      if (city_minl[i] <= min_size) {
        min_size = city_minl[i];
        ans = i;
      }
    }
    return ans;
  }

  void floyd(int n, int distanceThreshold) {
    for (int k = 0; k < n; k++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (dist[i][k] + dist[k][j] < dist[i][j]) {
            dist[i][j] = dist[i][k] + dist[k][j];
            // step[i][j] = step[i][k];
          }
        }
      }
    }
  }
  vector<vector<int>> dist;
  //   vector<vector<int>> step;
};

int main() {
  int n = 6;
  vector<vector<int>> edges = {{0, 3, 7},  {2, 4, 1}, {0, 1, 5},
                               {2, 3, 10}, {1, 3, 6}, {1, 2, 1}};
  int distanceThreshold = 417;
  Solution so;
  so.findTheCity(n, edges, distanceThreshold);
}