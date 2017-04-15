#include <bits/stdc++.h>
using namespace std;
const int maxn = 300050;

struct edge {
  int v;
  int id;
  edge(int v, int id) : v(v), id(id) {}
};
vector<edge> G[maxn];
int vis[maxn];
int mark[maxn];
int main()
{
  int n, k, d;
  scanf("%d %d %d", &n, &k, &d);
  queue<int> que;
  memset(vis, 0, sizeof(vis));
  memset(mark, 0, sizeof(mark));
  for (int i = 0; i < k; i++) {
    int x;
    scanf("%d", &x);
    que.push(x);
    vis[x] = 1;
  }
  for (int i = 1; i <= n - 1; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    G[u].emplace_back(edge(v, i));
    G[v].emplace_back(edge(u, i));
  }
  while (que.size()) {
    int now = que.front();
    que.pop();
    for (auto to: G[now]) {
      if (!vis[to.v]) {
        mark[to.id] = 1;
        vis[to.v] = 1;
        que.push(to.v);
      }
    }
  }
  int cnt = 0;
  for (int i = 1; i < n; i++)
    if (!mark[i])
      cnt++;    
  printf("%d\n", cnt);
  for (int i = 1; i < n; i++)
    if (!mark[i])
      printf("%d ", i);
  return 0;
}