#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
int a[N];
int solve(int *c, int l, int r)
{
  if (r - l == 1) {
    return c[l];
  }
  int m = (l + r) >> 1;
  int mx = max(solve(c, l, m), solve(c, m, r));
  int L = c[m - 1], R = c[m], v;
  v = 0;
  for (int i = m - 1; i >= l; i--) {
    L = max(L, v += c[i]);
  }
  v = 0;
  for (int i = m; i < r; i++) {
    R = max(R, v += c[i]);
  }
  return max(mx, L + R);
}
int main()
{
  int k;
  while (~scanf("%d", &k) && k) {
    for (int i = 0; i < k; i++) {
      scanf("%d", a + i);
    }
    int mx = solve(a, 0, k);
    printf("%d\n", mx);
  }
  return 0;
}