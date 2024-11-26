#include <map>
#include <set>
#include <vector>
using namespace std;
class Solution {
public:
  int winningPlayerCount(int n, vector<vector<int>> &pick) {
    map<int, map<int, int>> count;
    set<int> winners;

    for (const auto &p : pick) {
      int id = p[0];
      if (winners.find(id) != winners.end()) {
        continue;
      }
      int y = p[1];
      auto &player = count[id];
      player[y]++;
      if (player[y] > id) {
        winners.insert(id);
      }
    }
    return winners.size();
  }
};