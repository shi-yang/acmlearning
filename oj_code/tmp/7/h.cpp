#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
const int maxn = 1005;
int n, m;
struct edge {
  int b, c;
  edge (int bb, int cc) : b(bb), c(cc) {}
  bool operator < (const edge & a) const {
    return c < a.c;
  }
};
vector<edge> g[maxn];
int vis[maxn];
void prim()
{
  priority_queue<edge> que;
  for (int i = 0; i < g[1].size(); i++)
    que.push(g[1][i]);
  vis[1] = 1;
  long long ans = 0;
  while (que.size()) {
    edge now = que.top();
    que.pop();
    if (vis[now.b]) {
      continue;
    }
    vis[now.b] = 1;
    ans += now.c;
    for (int i = 0; i < g[now.b].size(); i++) {
      que.push(g[now.b][i]);
    }
  }
  for (int i = 1; i <= n; i++)
    if (!vis[i]) {
      printf("-1\n");
      return ;
    }
  printf("%d\n", ans);
}
int main()
{
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    g[x].emplace_back(edge(y, z));
    g[y].emplace_back(edge(x, z));
  }
  prim();
  return 0;
}
