#include <bits/stdc++.h>
using namespace std;
int n, a[100005];
int q, p, k;
map<pair<int, int>, int> t;
int main()
{
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d", a + i);
  scanf("%d", &q);
  while (q--) {
    int ans = 0;
    scanf("%d %d", &p, &k);
    if (t[make_pair(p, k)]) {
      printf("%d\n", t[make_pair(p, k)]);
      continue;
    }
    while (p <= n) {
      p = p + k + a[p];
      ans++;
    }
    t[make_pair(p, k)] = ans;
    printf("%d\n", ans);
  }
  return 0;
}