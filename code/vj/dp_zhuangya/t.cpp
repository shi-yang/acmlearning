#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 20;
int dis[N][N];
int dp[1 << N][N];
int main()
{
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    memset(dis, 0x3f, sizeof(dis));
    for (int i = 0; i < n; i++)
      dis[i][i] = 0;
    while (m--) {
      int u, v, w;
      scanf("%d %d %d", &u, &v, &w);
      u--;
      v--;
      dis[u][v] = dis[v][u] = min(dis[u][v], w);
    }
    for (int k = 0; k < n; k++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
        }
      }
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[(1 << n) - 1][0] = 0;
    for (int s = (1 << n) - 2; s >= 0; s--) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (s >> i & j) {
            continue;
          }
          dp[s][i] = min(dp[s][i], dp[s | 1 << j][j] + dis[i][j]);
        }
      }
    }
    printf("%d\n", dp[0][0]);
  }
  return 0;
}