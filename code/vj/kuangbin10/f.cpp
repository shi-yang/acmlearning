#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 3005;
struct people {
  int x, y, v;
}e[N];
struct umbrella {
  int x, y;
}u[N];
int n, m, t;
int xlink[N], ylink[N], dx[N], dy[N], vis[N];
int dis;
vector<int> G[N];
bool bfs()
{
  memset(dx, -1, sizeof(dx));
  memset(dy, -1, sizeof(dy));
  dis = INF;
  queue<int> que;
  for (int i = 0; i < n; i++) {
    if (xlink[i] == -1) {
      dx[i] = 0;
      que.push(i);
    }
  }
  while (!que.empty()) {
    int u = que.front();
    que.pop();
    if (dx[u] > dis)
      break;
    for (int i = 0; i < G[u].size(); i++) {
      int v = G[u][i];
      if (dy[v] == -1) {
        dy[v] = dx[u] + 1;
        if (ylink[v] == -1) {
          dis = dy[v];
        } else {
          dx[ylink[v]] = dy[v] + 1;
          que.push(ylink[v]);
        }
      }
    }
  }
  return dis != INF;
}
int dfs(int u)
{
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i];
    if (!vis[v] && dy[v] == dx[u] + 1) {
      vis[v] = 1;
      if (ylink[v] != -1 && dis == dy[v])
        continue;
      if (ylink[v] == -1 || dfs(ylink[v])) {
        ylink[v] = u;
        xlink[u] = v;
        return 1;
      }
    }
  }
  return 0;
}
int max_match()
{
  int res = 0;
  memset(xlink, -1, sizeof(xlink));
  memset(ylink, -1, sizeof(ylink));
  while (bfs()) {
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; i++) {
      if (xlink[i] == -1) {
        res += dfs(i);
      }
    }
  }
  return res;
}
int main()
{
  int tt;
  scanf("%d", &tt);
  for (int cas = 1; cas <= tt; cas++) {
    scanf("%d %d", &t, &m);
    for (int i = 0; i < m; i++) {
      scanf("%d %d %d", &e[i].x, &e[i].y, &e[i].v);
    }
    scanf("%d", &n);
    for (int j = 0; j < n; j++) {
      G[j].clear();
      scanf("%d %d", &u[j].x, &u[j].y);
      for (int i = 0; i < m; i++) {
        double dis = sqrt(1.0 * ((e[i].x - u[j].x) * (e[i].x - u[j].x) + (e[i].y - u[j].y) * (e[i].y - u[j].y)));
        if (dis <= 1.0 * e[i].v * t) {
          G[j].push_back(i);
        }
      }
    }
    int ans = max_match();
    printf("Scenario #%d:\n%d\n\n", cas, ans);
  }
  return 0;
}