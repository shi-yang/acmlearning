#include <bits/stdc++.h>
using namespace std;
const int N = 55;
int a[N];
int dp[N][N];
int main()
{
  int l;
  while (~scanf("%d", &l) && l) {
    int n;
    scanf("%d", &n);
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 1; i <= n; i++) {
      scanf("%d", a + i);
    }
    a[0] = 0;
    a[n + 1] = l;
    for (int i = 1; i <= n + 1; i++) {
      for (int j = 0; j + i <= n + 1; j++) {
        if (i == 1) {
          dp[j][j + i] = 0;
        }
        for (int k = j + 1; k < i + j; k++) {
          dp[j][j + i] = min(dp[j][j + i], dp[j][k] + dp[k][j + i] + a[i + j] - a[j]);
        }
      }
    }
    printf("The minimum cutting is %d.\n", dp[0][n + 1]);
  }
  return 0;
}