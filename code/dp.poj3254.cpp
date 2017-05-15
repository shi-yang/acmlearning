#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int md = 1e9;
int cur[20], state[600], dp[20][600];
int n, m, top;
bool fit(int x, int k)
{
  return !(x & cur[k]);
}
int main()
{
  while (~scanf("%d %d", &m, &n)) {
    top = 0;
    for (int i = 0; i < (1 << n); i++) {
      if (!(i & i << 1))
        state[++top] = i;
    }
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= m; i++) {
      cur[i] = 0;
      for (int j = 1; j <= n; j++) {
        int x; scanf("%d", &x);
        if (!x) {
          cur[i] += 1 << (n - j);
        }
      }
    }
    for (int i = 1; i <= top; i++) {
      if (fit(state[i], 1))
        dp[1][i] = 1;
    }
    for (int i = 2; i <= m; i++) {
      for (int j = 1; j <= top; j++) {
        if (!fit(state[j], i))
          continue;
        for (int k = 1; k <= top; k++) {
          if (!fit(state[k], i - 1) || (state[k] & state[j]))
            continue;
          dp[i][j] = (dp[i][j] + dp[i - 1][k]) % md;
        }
      }
    }
    int ans = 0;
    for (int i = 1; i <= top; i++) {
      ans = (ans + dp[m][i]) % md;
    }
    printf("%d\n", ans);
  }
  return 0;
}