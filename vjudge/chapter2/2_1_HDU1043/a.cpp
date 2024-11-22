#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int inf = 0x3f3f3f3f;
#define Maxn 362880 + 5 // 876543210的hash值为362880 即最多出现362880种可能
int C, N, M, T;
int A[3][3];
int step[Maxn];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
bool bound(int x, int y) {
  if (x >= 0 && x < 3 && y >= 0 && y < 3) {
    return true;
  }
  return false;
}

static const int FAC[] = {1,   1,   2,    6,     24,
                          120, 720, 5040, 40320, 362880}; // 阶乘
struct node {
  string path; //路径
  int hash;    // hash值
  int x;       // 0的位置
  int y;       // 0的位置
};
char op[5] = "lrud"; //这个与上面的搜索方向是反的，因为是反向bfs
int tmp[3][3];       //临时存储拼图的序列
int result = 46233; // 123456780    最终答案的hash值
int input = 0;
int input_mat[3][3];

string path[Maxn]; // path[x] hash值为x的路径

//康托展开
int cantor(int a[][3]) {
  int x = 0;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      int smaller = 0; // 在当前位之后小于其的个数
      int ki = i;
      int kj = j + 1;
      if (j == 2) {
        ki++;
        kj = 0;
      }
      for (; ki < 3; ki++) {
        for (; kj < 3; kj++) {
          if (a[ki][kj] < a[i][j]) {
            smaller++;
          }
        }
        kj = 0;
      }
      x += FAC[9 - (i * 3 + j) - 1] * smaller; // 康托展开累加
    }
  }

  return x; // 康托展开值
}
//逆康托展开
void decantor(int x, int a[][3]) {
  vector<int> v; // 存放当前可选数
  for (int i = 0; i < 9; i++)
    v.push_back(i);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      int r = x % FAC[9 - (i * 3 + j) - 1];
      int t = x / FAC[9 - (i * 3 + j) - 1];
      x = r;
      std::sort(v.begin(), v.end()); // 从小到大排序
      a[i][j] = v[t];                // 剩余数里第t+1个数为当前位
      v.erase(v.begin() + t);        // 移除选做当前位的数
    }
  }
}
std::queue<node> nodes;
void bfs() {
  memset(step, inf, sizeof(step));
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      tmp[i][j] = i * 3 + j + 1;
    }
  }
  tmp[2][2] = 0;
  step[result] = 0;
  path[result] = "";
  node start;
  start.hash = result;
  start.path = "";
  start.x = 2;
  start.y = 2;
  nodes.push(start);
  while (!nodes.empty()) {
    node cur = nodes.front();
    nodes.pop();
    for (int i = 0; i < 4; i++) {
      int nx = cur.x + dx[i];
      int ny = cur.y + dy[i];

      if (bound(nx, ny)) {
        decantor(cur.hash, tmp);
        swap(tmp[cur.x][cur.y], tmp[nx][ny]);
        int next_hash = cantor(tmp);
        if (step[cur.hash] + 1 < step[next_hash]) {
          step[next_hash] = step[cur.hash] + 1;
          path[next_hash] = op[i] + path[cur.hash];
          nodes.push({path[next_hash], next_hash, nx, ny});
        }
      }
    }
  }
}
int main() {
  memset(step, inf, sizeof(step));
  while (!nodes.empty()) {
    nodes.pop();
  }
  char x;
  bfs();
  while (cin >> x) //输入格式 没啥说的
  {
    if (x == 'x') {
      input_mat[0][0] = 0;
    } else {
      input_mat[0][0] = x - '0';
    }
    int j = 1;
    for (int i = 0; i < 3; i++) {
      for (; j < 3; j++) {
        cin >> x;
        if (x == 'x') {
          input_mat[i][j] = 0;
        } else {
          input_mat[i][j] = x - '0';
        }
      }
      j = 0;
    }

    input = cantor(input_mat);

    if (step[input] == inf) {
      cout << "unsolvable" << endl;
    } else {
      cout << path[input] << endl;
      // cout << step[end_.z][end_.x][end_.y] << endl;
    }
  }
  return 0;
}