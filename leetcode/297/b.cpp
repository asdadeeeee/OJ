#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <deque>
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
  //   void Stringsplit(const string &str, const char split, deque<string> &res)
  //   {
  //     if (str == "")
  //       return;
  //     //在字符串末尾也加入分隔符，方便截取最后一段
  //     string strs = str;
  //     size_t pos = strs.find(split);

  //     // 若找不到内容则字符串搜索函数返回 npos
  //     while (pos != strs.npos) {
  //       string temp = strs.substr(0, pos);
  //       res.push_back(temp);
  //       //去掉已分割的字符串,在剩下的字符串中进行分割
  //       strs = strs.substr(pos + 1, strs.size());
  //       pos = strs.find(split);
  //     }
  //   }

  // Encodes a tree to a single string.
  string serialize(TreeNode *root) {
    string ans;
    ser(root, ans);
    return ans;
  }

  void ser(TreeNode *root, string &s) {

    if (root == nullptr) {
      s.append("#");
    } else {
      s.append(to_string(root->val));
    }
    s.append(",");
    if (root != nullptr) {
      ser(root->left, s);
      ser(root->right, s);
    }
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(string data) {
    deque<string> sq;
    stringstream ss(data);
    string item;
    while (getline(ss, item, ',')) {
      sq.push_back(std::move(item));
    }
    return des(sq);
  }

  // Decodes your encoded data to tree.
  TreeNode *des(deque<string> &strings) {
    if (strings.empty()) {
      return nullptr;
    }
    string cur = strings.front();
    strings.pop_front();
    if (cur == "#") {
      return nullptr;
    }
    auto node = new TreeNode{stoi(cur)};
    node->left = des(strings);
    node->right = des(strings);
    return node;
  }
};
