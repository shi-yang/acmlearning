#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 1005;
const int M = 20005;
struct edge {
  int l, r, h;
  bool operator < (const edge &a) const {
    return h < a.h;
  }
} e[N];
int dp[N][2];
int main()
{
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, x, y, mx;
    scanf("%d %d %d %d", &n, &x, &y, &mx);
    for (int i = 1; i <= n; i++) {
      scanf("%d %d %d", &e[i].l, &e[i].r, &e[i].h);
    }
    sort(e + 1, e + n + 1);
    memset(dp, INF, sizeof(dp));
    for (int i = 1; i <= n; i++) {
      bool flag_l = 0, flag_r = 0;
      for (int j = i - 1; j >= 1; j--) {
        if (e[i].h - e[j].h > mx)
          continue;
        if (e[j].l <= e[i].l && e[i].l <= e[j].r && !flag_l) {
          flag_l = 1;
          dp[i][0] = min(e[i].l - e[j].l + dp[j][0], e[j].r - e[i].l + dp[j][1]) + e[i].h - e[j].h;
        }
        if (e[j].l <= e[i].r && e[i].r <= e[j].r && !flag_r) {
          flag_r = 1;
          dp[i][1] = min(e[i].r - e[j].l + dp[j][0], e[j].r - e[i].r + dp[j][1]) + e[i].h - e[j].h;
        }
        if (flag_l && flag_r)
          break;
      }
      if (!flag_l && e[i].h <= mx) {
        dp[i][0] = e[i].h;
      }
      if (!flag_r && e[i].h <= mx) {
        dp[i][1] = e[i].h;
      }
    }
    int m = n;
    while (m > 0) {
      if (e[m].l <= x && x <= e[m].r && y >= e[m].h)
        break;
      m--;
    }
    if (m == 0) {
      printf("%d\n", y);
    } else {
      printf("%d\n", min(x - e[m].l + dp[m][0], e[m].r - x + dp[m][1]) + y - e[m].h);
    }
  }
  return 0;
}
