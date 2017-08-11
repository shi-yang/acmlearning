#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 40005;
vector<pair<int, int> > G[N];
bool vis[N];
int dis[N];
int bfs(int s, bool flag)
{
  queue<int> que;
  que.push(s);
  int ans = 0;
  int point;
  memset(vis, 0, sizeof(vis));
  memset(dis, 0, sizeof(dis));
  vis[s] = 1;
  while (!que.empty()) {
    int u = que.front();
    que.pop();
    for (int i = 0; i < G[u].size(); i++) if (!vis[G[u][i].first]) {
      int v = G[u][i].first;
      vis[v] = true;
      dis[v] += G[u][i].second + dis[u];
      if (dis[v] > ans) {
        ans = dis[v];
        point = v;
      }
      que.push(v);
    }
  }
  return flag ? ans : point;
}
int main()
{
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v, c;
    scanf("%d %d %d %*c", &u, &v, &c);
    G[u].push_back(make_pair(v, c));
    G[v].push_back(make_pair(u, c));
  }
  printf("%d\n", bfs(bfs(1, false), true));
  return 0;
}