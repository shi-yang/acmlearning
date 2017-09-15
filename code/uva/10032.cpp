#include <bits/stdc++.h>
using namespace std;
const int N = 25005;
int dp[N];
int cnt[N][55];
int main()
{
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, sum = 0;
    scanf("%d", &n);
    memset(dp, 0, sizeof(dp));
    memset(cnt, 0, sizeof(cnt));
    cnt[0][0] = 1;
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
      int w;
      scanf("%d", &w);
      sum += w;
      for (int j = N - 1; j >= w; j--) {
        if (dp[j - w]) {
          dp[j] = 1;
          for (int k = 0; k <= 50; k++) {
            if (cnt[j - w][k])
              cnt[j][k + 1] = 1;
          }
        }
      }
    }
    int ans, xx = 0x3f3f3f3f;
    for (int i = 0; i < N; i++) {
      if (cnt[i][n / 2]) {
        int tmp = abs(sum - i - i);
        if (tmp < xx) {
          xx = tmp;
          ans = i;
        }
      }
    }
    int x = ans, y = sum - ans;
    if (x > y)
      swap(x, y);
    printf("%d %d\n", x, y);
    if (t)
      puts("");
  }
  return 0;
}