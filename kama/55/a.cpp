#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
void reverse(string &s, int left, int right) {
  while (left < right) {
    swap(s[left], s[right]);
    left++;
    right--;
  }
}
int main() {
  string s;
  int k;
  cin >> k;
  cin >> s;
  int n = s.size();
  reverse(s, 0, n - 1);
  reverse(s, 0, k - 1);
  reverse(s, k, n - 1);
  cout << s << endl;
}