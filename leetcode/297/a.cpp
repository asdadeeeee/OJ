#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
class Codec {

public:
  // void Stringsplit(const string &str, const char split, vector<string> &res)
  // {
  //   if (str == "")
  //     return;
  //   //在字符串末尾也加入分隔符，方便截取最后一段
  //   string strs = str;
  //   size_t pos = strs.find(split);

  //   // 若找不到内容则字符串搜索函数返回 npos
  //   while (pos != strs.npos) {
  //     string temp = strs.substr(0, pos);
  //     res.push_back(temp);
  //     //去掉已分割的字符串,在剩下的字符串中进行分割
  //     strs = strs.substr(pos + 1, strs.size());
  //     pos = strs.find(split);
  //   }
  // }

  // Encodes a tree to a single string.
  string serialize(TreeNode *root) {
    while (!nodes.empty()) {
      nodes.pop();
    }
    string ans;
    if (root == nullptr) {
      return ans;
    }
    nodes.push(root);
    while (!nodes.empty()) {
      auto cur = nodes.front();
      if (cur == nullptr) {
        ans.append("#");
      } else {
        ans.append(to_string(cur->val));
        nodes.push(cur->left);
        nodes.push(cur->right);
      }
      ans.append(",");
      nodes.pop();
    }
    return ans;
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(string data) {
    vector<string> strings;
    string item;
    stringstream ss(data);
    while (getline(ss, item, ',')) {
      strings.push_back(std::move(item));
    }
    // Stringsplit(data, ',', strings);
    while (!nodes.empty()) {
      nodes.pop();
    }
    if (data.length() == 0) {
      return nullptr;
    }
    auto root = new TreeNode{(stoi(strings[0]))};
    int idx = 1;
    nodes.push(root);
    while (!nodes.empty()) {
      auto cur = nodes.front();
      nodes.pop();
      auto c = strings[idx++];
      if (c != "#") {
        auto left = new TreeNode{stoi(c)};
        cur->left = left;
        nodes.push(left);
      }
      c = strings[idx++];
      if (c != "#") {
        auto right = new TreeNode{stoi(c)};
        cur->right = right;
        nodes.push(right);
      }
    }
    return root;
  }

  queue<TreeNode *> nodes;
};