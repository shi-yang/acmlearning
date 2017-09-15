#include <bits/stdc++.h>
using namespace std;
const int N = 10;
double cir[N];
int vis[N];
double rec[N], dis[N];
int n;
double ans;
void dfs(int cur)
{
  if (cur == n + 1) {
    double res = 0;
    for (int i = 1; i <= n; i++) {
      res = max(res, dis[i] + rec[i]);
    }
    ans = min(ans, res);
    return;
  }
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      vis[i] = 1;
      rec[cur] = cir[i];
      dis[cur] = cir[i];
      for (int j = 1; j < cur; j++) {
        if (dis[cur] < dis[j] + 2 * sqrt(rec[j] * rec[cur])) {
          dis[cur] = dis[j] + 2 * sqrt(rec[j] * rec[cur]);
        }
      }
      dfs(cur + 1);
      vis[i] = 0;
    }
  }
}
int main()
{
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%lf", cir + i);
    }
    dis[0] = 0;
    memset(vis, 0, sizeof(vis));
    ans = 0x7fffffff;
    dfs(1);
    printf("%.3lf\n", ans);
  }
  return 0;
}