#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
struct edge {
  int to;
  long long cost;
  edge(int tt, long long cc) : to(tt), cost(cc) {}
  edge() {}
  bool operator < (const edge &a) const {
    return a.cost < cost;
  }
};
bool vis[maxn];
priority_queue<edge> que;
vector<edge> G[maxn];

int n, m;

long long prim()
{
  long long res = 0;
  memset(vis, false, sizeof(vis));
  vis[1] = true;
  for (int i = 0; i < G[1].size(); i++) {
    que.push(G[1][i]);
  }
  while (que.size()) {
    edge e = que.top();
    que.pop();
    if (vis[e.to])
      continue;
    vis[e.to] = 1;
    res += e.cost;
    for (int i = 0; i < G[e.to].size(); i++) {
      que.push(G[e.to][i]);
    }
  }
  return res;
}

int main()
{
  while (cin >> m >> n) {
    if (m == 0)
      break;
    for (int i = 0; i < maxn; i++) {
      G[i].clear();
    }
    while (que.size())
      que.pop();
    for (int i = 0; i < m; i++) {
      int u, v;
      long long cost;
      cin >> u >> v >> cost;
      G[u].push_back(edge(v, cost));
      G[v].push_back(edge(u, cost));
    }
    long long res = prim();
    for (int i = 1; i <= n; i++) {
      if (!vis[i])
        res = -1;
    }
    if (res == -1) {
      cout << '?' << endl;
    } else {
      cout << res << endl;
    }
  }
  return 0;
}