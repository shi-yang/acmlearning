#include <bits/stdc++.h>
using namespace std;
const int N = 205;
int n, m;
vector<int> G[N];
int link[N], vis[N];
int dfs(int u)
{
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i];
    if (vis[v])
      continue;
    vis[v] = 1;
    if (link[v] == -1 || dfs(link[v])) {
      link[v] = u;
      return 1;
    }
  }
  return 0;
}
int bfs()
{
  memset(vis, 0, sizeof(vis));
  memset(link, -1, sizeof(link));
  queue<int> que;
  que.push(1);
  vis[1] = 1;
  link[1] = 0;
  while (!que.empty()) {
    int u = que.front();
    que.pop();
    for (int i = 0; i < G[u].size(); i++) {
      int v = G[u][i];
      if (!vis[v]) {
        link[v] = 1 - link[u];
        vis[v] = 1;
        que.push(v);
      } else if (link[v] == link[u]) {
        return 0;
      }
    }
  }
  return 1;
}
int main()
{
  while (~scanf("%d %d", &n, &m)) {
    for (int i = 0; i < N; i++)
      G[i].clear();
    for (int i = 0; i < m; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      G[u].push_back(v);
      G[v].push_back(u);
    }
    if (!bfs()) {
      puts("No");
      continue;
    }
    memset(link, -1, sizeof(link));
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      memset(vis, 0, sizeof(vis));
      cnt += dfs(i);
    }
    printf("%d\n", cnt / 2);
  }
  return 0;
}