#include <bits/stdc++.h>
using namespace std;
const int N = 105;
struct Point {
  double x, y;
} h[N], g[N];
vector<int> G[N];
int vis[N], match[N];
bool dfs(int x)
{
  for (auto v : G[x]) {
    if (!vis[v]) {
      vis[v] = 1;
      if (match[v] == -1 || dfs(match[v])) {
        match[v] = x;
        return true;
      }
    }
  }
  return false;
}
double dis(Point a, Point b)
{
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
int main()
{
  int n, m, s, v;
  while (~scanf("%d %d %d %d", &n, &m, &s, &v)) {
    for (int i = 0; i < n; i++)
      G[i].clear();
    for (int i = 0; i < n; i++) {
      scanf("%lf %lf", &g[i].x, &g[i].y);
    }
    for (int i = 0; i < m; i++) {
      scanf("%lf %lf", &h[i].x, &h[i].y);
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (dis(g[i], h[j]) <= 1.0 * s * v) {
          G[i].push_back(j);
        }
      }
    }
    int sum = 0;
    memset(match, -1, sizeof(match));
    for (int i = 0; i < n; i++) {
      memset(vis, 0, sizeof(vis));
      sum += dfs(i);
    }
    printf("%d\n", n - sum);
  }
  return 0;
}