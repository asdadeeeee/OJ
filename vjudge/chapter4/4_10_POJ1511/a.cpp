#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
typedef long long LL;
const LL inf = 0x3f3f3f3f3f3f3f3f;
bool choice;
int N;
int P, Q;
LL distA[1000002];
LL distB[1000002];
struct Node {
  int to, next;
  LL w;
} edgeA[1000002], edgeB[1000002];
int headA[1000002];
bool visitA[1000002];
int lenA = 1;
int headB[1000002];
bool visitB[1000002];
int lenB = 1;
struct cmp {
  bool operator()(int a, int b) {
    if (choice) {
      return distA[a] > distA[b];
    }
    return distB[a] > distB[b];
  }
};
void add(int u, int v, int dist, bool hint) {
  if (hint) {
    edgeA[lenA].next = headA[u];
    edgeA[lenA].w = dist;
    edgeA[lenA].to = v;
    headA[u] = lenA++;
  } else {
    edgeB[lenB].next = headB[u];
    edgeB[lenB].w = dist;
    edgeB[lenB].to = v;
    headB[u] = lenB++;
  }
}

LL dij(int start, LL dist[], bool visit[], Node edge[], int head[]) {
  dist[start] = 0;
  priority_queue<int, vector<int>, cmp> q;
  q.push(start);
  while (!q.empty()) {
    int cur = q.top();
    q.pop();
    if (visit[cur]) {
      continue;
    }
    visit[cur] = true;
    for (int i = head[cur]; i != 0; i = edge[i].next) {
      int v = edge[i].to;
      LL d = dist[cur] + edge[i].w;
      if (d < dist[v]) {
        dist[v] = d;
        q.push(v);
      }
    }
  }
  LL sum = 0;
  for (int i = 1; i <= P; i++)
    sum += dist[i];
  return sum;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> N;
  while (N--) {
    memset(headA, 0, sizeof(headA));
    memset(visitA, false, sizeof(visitA));
    memset(distA, 0x3f, sizeof(distA));

    memset(headB, 0, sizeof(headA));
    memset(visitB, false, sizeof(visitA));
    memset(distB, 0x3f, sizeof(distA));

    cin >> P >> Q;
    for (int i = 0; i < Q; i++) {
      int s, e, dist;
      cin >> s >> e >> dist;
      add(s, e, dist, true);
      add(e, s, dist, false);
    }
    choice = true;
    LL ans = 0;
    ans += dij(1, distA, visitA, edgeA, headA);
    choice = false;
    ans += dij(1, distB, visitB, edgeB, headB);
    cout << ans << endl;
  }
}