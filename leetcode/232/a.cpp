#include <stack>
using namespace std;
class MyQueue {
public:
  MyQueue() {}

  void push(int x) { next.push(x); }

  int pop() {
    if (cur.empty()) {
      fill();
    }
    int e = cur.top();
    cur.pop();
    return e;
  }

  int peek() {
    if (cur.empty()) {
      fill();
    }
    return cur.top();
  }

  bool empty() {
    if (cur.empty()) {
      fill();
    }
    return cur.empty();
  }

private:
  inline void fill() {
    while (!next.empty()) {
      int e = next.top();
      next.pop();
      cur.push(e);
    }
  }

private:
  stack<int> next;
  stack<int> cur;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */