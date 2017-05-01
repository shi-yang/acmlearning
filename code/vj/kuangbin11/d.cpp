#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <cstdlib>
#include <cstring>
using namespace std;
const int inf = 1e9;
const int maxn = 300;
int n, m;
char mp[105][105];
struct edge {
  int x, y;
}p[maxn], h[maxn];
int G[maxn][maxn];
int cost[maxn][maxn];
int cap[maxn][maxn];
int d[maxn];
int inq[maxn];
int pre[maxn];
int cnt;
bool spfa(int s, int t)
{
  for (int i = 0; i < maxn; i++)
    d[i] = inf, inq[i] = 0;
  queue<int> que;
  que.push(s);
  inq[s] = 1;
  d[s] = 0;
  while (!que.empty()) {
    int now = que.front();
    que.pop();
    inq[now] = 0;
    for (int i = 0; i <= cnt; i++) {
      if (cap[now][i] > 0 && d[i] > d[now] + cost[now][i]) {
        d[i] = d[now] + cost[now][i];
        pre[i] = now;
        if (inq[i])
          continue;
        inq[i] = 1;
        que.push(i);
      }
    }
  }
  if (d[t] != inf)
    return true;
  else
    return false;
}
int mcms(int s, int t)
{
  int res = 0;
  while (spfa(s, t)) {
    int mi = inf;
    for (int i = t; i != s; i = pre[i]) {
      cap[i][pre[i]]++;
      cap[pre[i]][i]--;
      res += cost[pre[i]][i];
    }
  } 
  return res;
}
int main()
{
  while (~scanf("%d %d", &n, &m) && (n + m)) {
    memset(cap, 0, sizeof(cap));
    memset(cost, 0, sizeof(cost));
    int p_cnt = 0, h_cnt = 0;
    for (int i = 0; i < n; i++) {
      scanf("%s", mp[i]);
      for (int j = 0; j < m; j++) {
        if (mp[i][j] == 'm') {
          p[p_cnt++] = (edge){i, j};
        } else if (mp[i][j] == 'H') {
          h[h_cnt++] = (edge){i, j};
        }
      }
    }
    int ph_cnt = p_cnt + h_cnt;
    int s = ph_cnt + 1, t = ph_cnt + 2;
    cnt = t;
    for (int i = 0; i < p_cnt; i++) {
      cost[s][i] = 0;
      cap[s][i] = 1;
    }
    for (int i = 0; i < h_cnt; i++) {
      cost[i + p_cnt][t] = 0;
      cap[i + p_cnt][t] = 1;
    }
    for (int i = 0; i < p_cnt; i++) {
      for (int j = 0; j < h_cnt; j++) {
        int dx = abs(p[i].x - h[j].x);
        int dy = abs(p[i].y - h[j].y);
        cost[i][j + p_cnt] = dx + dy;
        cost[j + p_cnt][i] = -(dx + dy);
        cap[i][j + p_cnt] = 1;
      }
    }
    int ans = mcms(s, t);
    printf("%d\n", ans);
  }
  return 0;
}
