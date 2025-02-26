#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main() {
  string s;
  cin >> s;
  string ans;
  for (char c : s) {
    if (c >= '0' && c <= '9') {
      ans += "number";
    } else {
      ans += c;
    }
  }
  cout << ans << endl;
}