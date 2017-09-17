#include <iostream>
#include <cstdio>
using namespace std;
const int N = 15;
const int md = 100000000;
int cur[N];
int dp[N][1 << 13];
int main()
{
  int m, n;
  scanf("%d %d", &m, &n);
  for (int i = 1; i <= m; i++) {
    for (int j = 0; j < n; j++) {
      int x;
      scanf("%d", &x);
      if (!x) {
        cur[i] |= 1 << j;
      }
    }
  }
  for (int i = 1; i <= m; i++) {
    for (int j = 0; j < 1 << n; j++) {
      if (cur[i] & j || j & j << 1) {
        continue;
      }
      if (i == 1) {
        dp[i][j] = 1;
        continue;
      }
      for (int k = 0; k < 1 << n; k++) {
        if (k & k << 1 || cur[i - 1] & k || k & j)
          continue;
        dp[i][j] = (dp[i][j] + dp[i - 1][k]) % md;
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < 1 << n; i++) {
    ans = (ans + dp[m][i]) % md;
  }
  printf("%d\n", ans);
  return 0;
}