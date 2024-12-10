#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  int removeElement(vector<int> &nums, int val) {
    int size = nums.size();
    int fast = 0;
    int slow = 0;
    while (fast < size) {
      if (nums[fast] == val) {
        fast++;
        if (fast == size) {
          break;
        }
      }
      if (nums[fast] != val) {
        nums[slow] = nums[fast];
        slow++;
        fast++;
      }
    }
    return slow;
  }
};