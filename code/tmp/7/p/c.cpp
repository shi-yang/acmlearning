#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int a[maxn], sum[maxn];
int main()
{
  int n, t;
  scanf("%d %d", &n, &t);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    if (!i)
      sum[i] = a[i];
    else
      sum[i] += sum[i - 1] + a[i];
  }
  int ans = 0, pos = 0, cnt = 0;
  for (int i = 0; i < n; i++) {
    t -= a[i];
    if (t < 0) {
      t += a[pos];
      pos++;
    } else {
      cnt++;
    }
    ans = max(ans, cnt);
  }
  printf("%d\n", ans);
  return 0;
}
