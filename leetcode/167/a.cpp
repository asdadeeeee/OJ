
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  void print(vector<int> &s) {
    for (const auto c : s) {
      cout << c;
    }
  }
  vector<int> twoSum(vector<int> &numbers, int target) {
    int size = numbers.size();
    int left = 0;
    int right = size - 1;
    while (left < right) {
      int temp = numbers[left] + numbers[right];
      if (temp < target) {
        left++;
      } else if (temp > target) {
        right--;
      } else {
        return {left + 1, right + 1};
      }
    }
    return {left + 1, right + 1};
  }
};

int main() {
  vector<int> numbers = {-10, -8, -2, 1, 2, 5, 6};
  Solution so;
  auto res = so.twoSum(numbers, 0);
  so.print(res);
}