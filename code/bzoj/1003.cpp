#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 105;
int dis[N];
int cost[N][N], stop[N][N], none[N];
long long dp[N];
vector<pair<int, int> > G[N];
int n, m, k, e, d;
int dijkstra(int l, int r)
{
  int s = 1;
  memset(dis, inf, sizeof(dis));
  memset(none, 0, sizeof(dis));
  priority_queue<pair<int, int> > que;
  for (int i = 1; i <= m; i++) {
    for (int j = l; j <= r; j++)
      none[i] |= stop[i][j];
  }
  que.push(make_pair(0, s));
  dis[s] = 0;
  while (!que.empty()) {
    int now = que.top().second;
    que.pop();
    for (int i = 0; i < G[now].size(); i++) {
      int to = G[now][i].first;
      if (!none[to] && dis[to] > dis[now] + G[now][i].second) {
        dis[to] = dis[now] + G[now][i].second;
        que.push(make_pair(-dis[to], to));
      }
    }
  }
  return dis[m];
}
int main()
{
  scanf("%d %d %d %d", &n, &m, &k, &e);
  for (int i = 0; i < e; i++) {
    int u, v, c;
    scanf("%d %d %d", &u, &v, &c);
    G[u].push_back(make_pair(v, c));
    G[v].push_back(make_pair(u, c));
  }
  scanf("%d", &d);
  for (int i = 0; i < d; i++) {
    int p, a, b;
    scanf("%d %d %d", &p, &a, &b);
    for (int j = a; j <= b; j++)
      stop[p][j] = 1;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cost[i][j] = dijkstra(i, j);
    }
  }
  for (int i = 1; i <= n; i++) {
    dp[i] = 1LL * cost[1][i] * i;
    for (int j = 1; j < i; j++) {
      dp[i] = min(dp[i], dp[j] + 1LL * cost[j + 1][i] * (i - j) + k);
    }
  }
  printf("%d", dp[n]);
  return 0;
}