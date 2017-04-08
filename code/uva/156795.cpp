#include <bits/stdc++.h>
using namespace std;
const int maxn = 20;
const int inf = 1e9;
int n, a[maxn][maxn], b[maxn][maxn];
int check(int s)
{
  memset(b, 0, sizeof(b));
  for (int i = 0; i < n; i++) {
    if (s & (1 << i)) {
      b[0][i] = 1;
    } else if (a[0][i] == 1) {
      return inf;
    }
  }
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int sum = 0;
      if (i > 1)
        sum += b[i - 2][j];
      if (j > 0)
        sum += b[i - 1][j - 1];
      if (j < n - 1)
        sum += b[i - 1][j + 1];
      b[i][j] = sum % 2;
      if (a[i][j] == 1 && b[i][j] == 0)
        return inf;
    }
  }
  int cnt = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (a[i][j] != b[i][j])
        cnt++;
  return cnt;
}
int main()
{
  int t;
  scanf("%d", &t);
  for (int cas = 1; cas <= t; cas++) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        scanf("%d", &a[i][j]);
      }
    }
    int ans = inf;
    for (int i = 0; i < (1 << n); i++) {
      ans = min(ans, check(i));
    }
    if (ans == inf)
      ans = -1;
    printf("Case %d: %d\n", cas, ans);
  }
  return 0;
}
