#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;
const int N = 30005;
const int E = 150005;
const int inf = 0x3f3f3f3f;
int dis[N];
int inq[N];
int head[E];
struct edge {
  int v, c;
  int next;
} e[E];
int top;
void add(int u, int v, int c)
{
  e[top].v = v;
  e[top].c = c;
  e[top].next = head[u];
  head[u] = top++;
}
void spfa(int s, int t)
{
  memset(inq, 0, sizeof(inq));
  memset(dis, inf, sizeof(dis));
  stack<int> que;
  que.push(s);
  dis[s] = 0;
  inq[s] = 1;
  while (que.size()) {
    int now = que.top();
    que.pop();
    inq[now] = 0;
    for (int i = head[now]; i != -1; i = e[i].next) {
      int v = e[i].v;
      if (dis[v] > dis[now] + e[i].c) {
        dis[v] = dis[now] + e[i].c;
        if (inq[v])
          continue;
        que.push(v);
        inq[v] = 1;
      }
    }
  }
}
int main()
{
  int n, m;
  scanf("%d %d", &n, &m);
  memset(head, -1, sizeof(head));
  for (int i = 0; i < m; i++) {
    int u, v, c;
    scanf("%d %d %d", &u, &v, &c);
    add(u, v, c);
  }
  spfa(1, n);
  printf("%d\n", dis[n]);
  return 0;
}