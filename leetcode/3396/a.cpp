#include <iostream>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  int minimumOperations(vector<int> &nums) {
    unordered_set<int> over_nums;
    unordered_map<int, int> count;
    for (auto n : nums) {
      count[n]++;
      if (count[n] > 1) {
        over_nums.insert(n);
      }
    }
    int ptr = 0;
    int size = nums.size();
    while (!over_nums.empty() && ptr < size) {
      count[nums[ptr]]--;
      if (count[nums[ptr]] <= 1) {
        over_nums.erase(nums[ptr]);
      }
      ptr++;
    }
    if (ptr == 0) {
      return 0;
    }
    return (ptr - 1) / 3 + 1;
  }
};

int main() {

  vector<int> num{6, 7, 8, 9};
  Solution so;
  cout << so.minimumOperations(num);
}