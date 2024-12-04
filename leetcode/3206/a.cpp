#include <vector>
using namespace std;
class Solution {
public:
  int nextidx(int cur, int k) { return (cur + 1) % k; }
  int preidx(int cur, int k) {
    if (cur == 0) {
      return k - 1;
    } else {
      return cur - 1;
    }
  }
  bool isAlter(int cur, vector<int> &colors) {
    int size = colors.size();
    if (colors.at(nextidx(cur, size)) != colors.at(cur) &&
        colors.at(preidx(cur, size)) != colors.at(cur)) {
      return true;
    }
    return false;
  }
  int numberOfAlternatingGroups(vector<int> &colors) {
    int ans = 0;
    for (int i = 0; i < colors.size(); i++) {
      if (isAlter(i, colors)) {
        ans++;
      }
    }
    return ans;
  }
};