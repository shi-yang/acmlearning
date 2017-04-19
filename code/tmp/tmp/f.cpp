#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int w[maxn], v[maxn];
int dp[maxn][maxn];
int main()
{
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, c;
    scanf("%d %d", &n, &c);
    for (int i = 0; i < n; i++) {
      scanf("%d", v + i); 
    }
    for (int i = 0; i < n; i++)
      scanf("%d", w + i);
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= c; j++) {
        if (j >= w[i])
          dp[i + 1][j] = max(dp[i][j], dp[i][j - w[i]] + v[i]);
        else
          dp[i + 1][j] = dp[i][j];
      }
    }
    printf("%d\n", dp[n][c]);
  }
  return 0;
}