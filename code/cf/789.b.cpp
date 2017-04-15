#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e9 + 5;
map<long long, long long> mp;
long long mabs(long long x)
{
  return x < 0 ? -x : x;
}
int main()
{
  long long b, q, m, l;
  scanf("%I64d %I64d %I64d %I64d", &b, &q, &l, &m);
  for (long long i = 0; i < m; i++) {
    long long x;
    scanf("%I64d", &x);
    mp[x] = 1;
  }
  long long ans = inf;
  if (b == 0) {
    if (mp[0])
      ans = 0;
  } else if (q == 0) {
    if (mp[0] || mabs(b) > l) {
      if (mp[b] || mabs(b) > l)
        ans = 0;
      else
        ans = 1;
    }
  } else if (q == 1) {
    if (mabs(b) > l || mp[b])
      ans = 0;
  } else if (q == -1) {
    if ((mp[-b] && mp[b]) || mabs(b) > l)
      ans = 0;
  } else {
    ans = 0;
    while (mabs(b) <= l) {
      if (!mp[b])
        ans++;
      b *= q;
    }
  }
  if (ans == inf)
    printf("inf\n");
  else
    printf("%I64d\n", ans);
  return 0;
}