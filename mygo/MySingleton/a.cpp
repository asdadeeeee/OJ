#include <iostream>
using namespace std;
class MySingleton {
public:
  static MySingleton &Instance() {
    static MySingleton instance{};
    return instance;
  }
  int getvalue() { return data; }
  void setvalue(int v) { data = v; }

private:
  MySingleton(const MySingleton &t) = delete;
  MySingleton(MySingleton &&t) = delete;
  MySingleton &operator=(const MySingleton &t) = delete;
  MySingleton &operator=(MySingleton &&t) = delete;
  MySingleton() = default;
  ~MySingleton() = default;
  int data;
};

int main() {
  cout << MySingleton::Instance().getvalue();
  MySingleton::Instance().setvalue(4);
  cout << MySingleton::Instance().getvalue();
}