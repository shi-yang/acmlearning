#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int inf = 0x3f3f3f3f;
int dp[1 << 16][16];
int main()
{
  int n, g[20][20];
  while (~scanf("%d", &n)) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        scanf("%d", &g[i][j]);
      }
    }
    memset(dp, inf, sizeof(dp));
    dp[(1 << n) - 1][0] = 0;
    for (int s = (1 << n) - 2; s >= 0; s--) {
      for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
          if (s & 1 << v || !g[u][v])
            continue;
          dp[s][u] = min(dp[s][u], dp[s | 1 << v][v] + g[u][v]);
        }
      }
    }
    if (dp[0][0] == inf) {
      puts("NoAnswer");
    } else {
      printf("%d\n", dp[0][0]);
    }
  }
  return 0;
}