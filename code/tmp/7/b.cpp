#include <bits/stdc++.h>
using namespace std;
const int maxn = 5005;
int n, m;
struct edge {
  int a, b, c;
  bool operator < (const edge & a) const {
    return c < a.c;
  }
} e[maxn];
int f[maxn];
int root(int x)
{
  return x == f[x] ? x : f[x] = root(f[x]);
}
int main()
{
  while (~scanf("%d %d", &n, &m) && (n + m)) {
    for (int i = 0; i < m; i++) {
      int a, b, c;
      scanf("%d %d %d", &e[i].a, &e[i].b, &e[i].c);
    }
    sort(e, e + m);
    int ans = 1e9;
    for (int k = 0; k <= m - n + 1; k++) {
      for (int i = 1; i <= n; i++) {
        f[i] = i;
      }
      int mx = 0, mi = 1e9;
      for (int i = k; i < m; i++) {
        int a = root(e[i].a), b = root(e[i].b);
        if (a != b) {
          f[a] = b;
          mx = max(mx, e[i].c);
          mi = min(mi, e[i].c);
        }
      }
      int ok = 1;
      for (int i = 2; i <= n; i++) {
        if (root(1) != root(i)) {
          ok = 0;
          break;
        }
      }
      if (ok) {
        ans = min(ans, mx - mi);
      }
    }
    if (ans == 1e9) {
      ans = -1;
    }
    printf("%d\n", ans);
  }
  return 0;
}
