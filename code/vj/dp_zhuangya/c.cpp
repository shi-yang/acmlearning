#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 17;
const int inf = 0x3f3f3f3f;
int G[N][N];
int n, eng;
int v[N], e[N];
int dp[1 << N], m[1 << N];
int main()
{
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &n, &eng);
    for (int i = 0; i < n; i++) {
      scanf("%d", v + i);
    }
    for (int i = 0; i < n; i++) {
      scanf("%d", e + i);
    }
    memset(G, 0, sizeof(G));
    for (int i = 0; i < n; i++) {
      int x, y;
      scanf("%d", &x);
      while (x--) {
        scanf("%d", &y);
        y--;
        G[i][y] = 1;
      }
    }
    int ans = 0;
    memset(dp, -1, sizeof(dp));
    memset(m, 0, sizeof(m));
    m[0] = eng;
    dp[0] = 0;
    for (int s = 0; s < 1 << n; s++) {
      for (int i = 0; i < n; i++) {
        if (!(s & 1 << i))
          continue;
        int sta = s - (1 << i);
        if (dp[sta] == -1)
          continue;
        int ok = 1;
        for (int j = 0; j < n; j++) {
          if (G[i][j] && !(s & 1 << j)) {
            ok = 0;
            break;
          }
        }
        if (!ok || m[sta] < e[i])
          continue;
        if (dp[s] < dp[sta] + v[i]) {
          dp[s] = dp[sta] + v[i];
          m[s] = m[sta] - e[i];
        }
      }
      ans = max(ans, dp[s]);
    }
    printf("%d\n", ans);
  }
  return 0;
}