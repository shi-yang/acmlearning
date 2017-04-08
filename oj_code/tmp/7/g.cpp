#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn = 1005;
const int inf = 1e9;
int n, m, x;
int inq[maxn];
int d[maxn][maxn];
vector<pair<int, int> > G[maxn];
int spfa(int s)
{
  memset(inq, 0, sizeof(inq));
  for (int i = 1; i <= n; i++) {
    d[s][i] = inf;
  }
  inq[s] = 1;
  d[s][s] = 0;
  queue<int> que;
  que.push(s);
  while (que.size()) {
    int now = que.front();
    que.pop();
    inq[now] = 0;
    for (int i = 0; i < G[now].size(); i++) {
      int v = G[now][i].first;
      if (d[s][v] > d[s][now] + G[now][i].second) {
        d[s][v] = d[s][now] + G[now][i].second;
        if (inq[v])
          continue;
        inq[v] = 1;
        que.push(v);
      }
    }
  }
}
int main()
{
  scanf("%d %d %d", &n, &m, &x);
  for (int i = 0; i < m; i++) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    G[a].push_back(make_pair(b, c));
  }
  for (int i = 1; i <= n; i++) {
    spfa(i);
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, d[i][x] + d[x][i]);
  }
  printf("%d\n", ans);
  return 0;
}
