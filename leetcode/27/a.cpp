#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  int removeElement(vector<int> &nums, int val) {
    auto iter = nums.begin();
    while (iter != nums.end()) {
      while (*iter == val) {
        nums.erase(iter);
        if (iter == nums.end()) {
          return nums.size();
        }
      }
      iter++;
    }
    return nums.size();
  }
};

int main() {
  vector<int> nums = {3, 2, 2, 3};
  Solution sol;
  int res = sol.removeElement(nums, 3);
  cout << res;
}