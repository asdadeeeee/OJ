#include <iostream>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  int minimumOperations(vector<int> &nums) {
    unordered_map<int, int> count;
    for (int i = nums.size() - 1; i >= 0; i--) {
      count[nums[i]]++;
      if (count[nums[i]] > 1) {
        return i / 3 + 1;
      }
    }
    return 0;
  }
};

int main() {

  vector<int> num{6, 7, 8, 9};
  Solution so;
  cout << so.minimumOperations(num);
}