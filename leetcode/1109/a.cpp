#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n) {
    vector<int> res(n, 0);
    for (const auto &book : bookings) {
      res[book[0] - 1] += book[2];
      if (book[1] < n) {
        res[book[1]] -= book[2];
      }
    }
    for (int i = 1; i < n; i++) {
      res[i] += res[i - 1];
    }
    return res;
  }
};
int main() {
  int length = 5;
  vector<vector<int>> updates = {{1, 2, 10}, {2, 3, 20}, {2, 5, 25}};
  Solution so;
  auto res = so.corpFlightBookings(updates, length);
  for (auto r : res) {
    cout << r << " ";
  }
}