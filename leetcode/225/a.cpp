#include <queue>
using namespace std;
class MyStack {
public:
  MyStack() {}

  void push(int x) {
    int n = q.size();
    q.push(x);
    while (n--) {
      int head = q.front();
      q.pop();
      q.push(head);
    }
  }

  int pop() {
    int e = q.front();
    q.pop();
    return e;
  }

  int top() { return q.front(); }

  bool empty() { return q.empty(); }

private:
  queue<int> q;
};