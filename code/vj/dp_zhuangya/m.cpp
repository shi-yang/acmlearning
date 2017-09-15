#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 30000;
int state[N], a[25][25];
int dp[25][N];
int main()
{
  int n;
  while (~scanf("%d", &n)) {
    int cnt = 0;
    for (int i = 0; i < 1 << n; i++) {
      if (i & i << 1)
        continue;
      state[cnt++] = i;
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < n; j++) {
        scanf("%d", &a[i][j]);
      }
    }
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < cnt; j++) {
        for (int k = 0; k < n; k++) {
          if (state[j] & 1 << k) {
            dp[i][j] += a[i][k];
          }
        }
        int tmp = 0;
        for (int k = 0; k < cnt; k++) {
          if (state[j] & state[k]) {
            continue;
          }
          tmp = max(tmp, dp[i - 1][k]);
        }
        dp[i][j] += tmp;
      }
    }
    int ans = 0;
    for (int i = 0; i < cnt; i++) {
      ans = max(ans, dp[n][i]);
    }
    printf("%d\n", ans);
  }
  return 0;
}