
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
  string back(string str) {
    string res;
    int len = 0;
    int n = str.length();
    int ptr1 = n - 1;
    while (ptr1 >= 0) {
      if (str[ptr1] == '#') {
        int ptr2 = ptr1 - 1;
        while (ptr2 >= 0) {
          if (str[ptr2] != '#' && str[ptr2] != '+') {
            str[ptr2] = '+';
            break;
          }
          ptr2--;
        }
      }
      ptr1--;
    }
    for (int i = 0; i < n; i++) {
      if (str[i] != '#' && str[i] != '+') {
        res.push_back(str[i]);
      }
    }
    return res;
  }
  bool backspaceCompare(string s, string t) {
    string ress = back(s);
    string rest = back(t);
    return ress.compare(rest) == 0;
  }
};

int main() {
  Solution so;
  cout << so.back("bxj##tw") << endl;
  cout << so.back("bxo#j##tw") << endl;
  if (so.backspaceCompare("bxj##tw", "bxo#j##tw")) {
    cout << 1;
  } else {
    cout << 0;
  };
}