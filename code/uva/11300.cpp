#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000010;
long long a[maxn], b[maxn], tot, m;
int main()
{
  int n;
  while (~scanf("%d", &n)) {
    tot = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%lld", &a[i]);
      tot += a[i];
    }
    m = tot / n;
    b[0] = 0;
    for (int i = 1; i <= n; i++) {
      b[i] = b[i - 1] + a[i] - m;
    }
    sort(b, b + n);
    long long t = b[n / 2], ans = 0;
    for (int i = 0; i < n; i++) {
      ans += abs(t - b[i]);
    }
    printf("%lld\n", ans);
  }
  return 0;
}
