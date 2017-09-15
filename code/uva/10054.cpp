#include <bits/stdc++.h>
using namespace std;
const int N = 55;
int G[N][N];
int cnt[N], vis[N];
void dfs(int x)
{
  for (int i = 0; i < N; i++) {
    if (G[x][i]) {
      G[x][i]--;
      G[i][x]--;
      dfs(i);
      printf("%d %d\n", i, x);
    }
  }
}
int main()
{
  int t, cas = 1;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    memset(G, 0, sizeof(G));
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      G[u][v]++;
      G[v][u]++;
      cnt[u]++;
      cnt[v]++;
    }
    printf("Case #%d\n", cas++);
    int ok = 1;
    for (int i = 1; i < N; i++) {
      if (cnt[i] & 1) {
        ok = 0;
        break;
      }
    }
    if (!ok) {
      puts("some beads may be lost");
    } else {
      memset(vis, 0, sizeof(vis));
      for (int i = 1; i < N; i++) {
        dfs(i);
      }
    }
    if (t) {
      puts("");
    }
  }
  return 0;
}