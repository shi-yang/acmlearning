#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[10000];
int main()
{
  int n, q;
  int cas = 1;
  //freopen("data.in", "r", stdin);
  while (scanf("%d%d", &n, &q) != EOF && (n && q)) {
    printf("CASE# %d:\n", cas++);
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    sort(a, a + n);
    while (q--) {
      int x;
      scanf("%d", &x);
      int ans = lower_bound(a, a + n, x) - a;
      if (a[ans] == x) {
        printf("%d found at %d\n", x, ans + 1);
      } else {
        printf("%d not found\n", x);
      }
    }
  }
  return 0;
}
