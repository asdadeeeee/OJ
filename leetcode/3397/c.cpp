#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;
class Solution {
public:
  int maxDistinctElements(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end());

    // 2. 使用集合来记录已经分配的值
    set<int> usedValues;

    // 3. 遍历数组
    for (int num : nums) {
      // 尝试在 [num - k, num + k] 范围内找到一个未使用的值
      for (int candidate = num - k; candidate <= num + k; ++candidate) {
        if (usedValues.find(candidate) == usedValues.end()) {
          // 如果找到未使用的值，加入集合并停止尝试
          usedValues.insert(candidate);
          break;
        }
      }
    }

    // 返回集合的大小，即可能拥有的最大不同元素数量
    return usedValues.size();
  }
};

int main() {
  vector<int> nums{65, 64, 65, 61};
  Solution so;
  cout << so.maxDistinctElements(nums, 58);
}