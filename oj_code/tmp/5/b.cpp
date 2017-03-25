#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int maxn = 105;
struct edge {
  int x, y;
  int op;
  int d, pre;
}e[maxn * maxn];
//f1, f2, p12, p21, d1, d2
//0   1    2    3   4   5
int m[105][105];
int a, b, c;
int path[maxn * maxn];
int bfs()
{
  queue<edge> que;
  int cnt = 0;
  que.push(edge{0, 0, -1, 0, cnt});
  m[0][0] = 1;
  while (!que.empty()) {
    e[++cnt] = que.front();
    edge now = e[cnt];
    que.pop();
    if (now.x == c || now.y == c) {
      return cnt;
    }
    //f1
    if (!m[a][now.y]) {
      m[a][now.y] = 1;
      que.push(edge{a, now.y, 0, now.d + 1, cnt});
    }
    //f2
    if (!m[now.x][b]) {
      m[now.x][b] = 1;
      que.push(edge{now.x, b, 1, now.d + 1, cnt});
    }
    //p12
    if (now.x > 0) {
      int t = min(b - now.y, now.x);
      if (!m[now.x - t][now.y + t]) {
        m[now.x - t][now.y + t] = 1;
        que.push(edge{now.x - t, now.y + t, 2, now.d + 1, cnt});
      }
    }
    //p21
    if (now.y > 0) {
      int t = min(a - now.x, now.y);
      if (!m[now.x + t][now.y - t]) {
        m[now.x + t][now.y - t] = 1;
        que.push(edge{now.x + t, now.y - t, 3, now.d + 1, cnt});
      }
    }
    //d1
    if (!m[0][now.y]) {
      m[0][now.y] = 1;
      que.push(edge{0, now.y, 4, now.d + 1, cnt});
    }
    //d2
    if (!m[now.x][0]) {
      m[now.x][0] = 1;
      que.push(edge{now.x, 0, 5, now.d + 1, cnt});
    }
  }
  return 0;
}
int main()
{
  while (cin >> a >> b >> c) {
    memset(m, 0, sizeof(m));
    int pos = bfs();
    if (pos) {
      cout << e[pos].d << endl;
      int cnt = 0;
      for (int i = pos; i != 1; i = e[i].pre) {
        path[++cnt] = e[i].op;
      }
      for (int i = cnt; i > 0; i--) {
        switch (path[i]) {
          case 0: cout << "FILL(1)" << endl; break;
          case 1: cout << "FILL(2)" << endl; break;
          case 2: cout << "POUR(1,2)" << endl; break;
          case 3: cout << "POUR(2,1)" << endl; break;
          case 4: cout << "DROP(1)" << endl; break;
          case 5: cout << "DROP(2)" << endl; break;
        }
      }
    } else {
      cout << "impossible" << endl;
    }
  }
  return 0;
}
