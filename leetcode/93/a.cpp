#include <string>
#include <vector>
using namespace std;
class Solution {
public:
  bool valid(string s) {
    if (s.length() > 3 || s.length() < 0) {
      return false;
    }
    if (s.length() > 1 && s[0] == '0') {
      return false;
    }
    int v = stoi(s);
    if (v > 255 || v < 0) {
      return false;
    }
    return true;
  }
  void split(string s, int rest) {
    if (rest == 1) {
      if (valid(s)) {
        cur.push_back(stoi(s));
        ans.emplace_back(cur);
        cur.pop_back();
      }
      return;
    }
    int n = s.length();
    for (int i = 1; i <= min(3, n - rest + 1); i++) {
      string left = s.substr(0, i);
      if (valid(left)) {
        cur.push_back(stoi(left));
        split(s.substr(i, n - i), rest - 1);
        cur.pop_back();
      }
    }
  }

  string change(vector<int> &a) {
    string ip;
    for (int e : a) {
      ip += to_string(e) + '.';
    }
    ip.pop_back();
    return ip;
  }

  vector<string> restoreIpAddresses(string s) {
    split(s, 4);
    for (auto a : ans) {
      res.emplace_back(change(a));
    }
    return res;
  }

  vector<int> cur;
  vector<vector<int>> ans;
  vector<string> res;
  string ip;
};
int main() {
  Solution so;
  so.restoreIpAddresses("0279245587303");
}