#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;
class Solution {
public:
  string getHint(string secret, string guess) {
    int length = secret.length();
    vector<int> countS(10, 0);
    vector<int> countG(10, 0);
    int cows = 0;
    int bolls = 0;
    for (int i = 0; i < length; i++) {
      if (secret[i] == guess[i]) {
        bolls++;
      } else {
        countG[guess[i] - '0']++;
        countS[secret[i] - '0']++;
      }
    }
    for (int i = 0; i < 9; i++) {
      cows += min(countS[i], countG[i]);
    }
    return to_string(bolls) + "A" + to_string(cows) + "B";
  }
};