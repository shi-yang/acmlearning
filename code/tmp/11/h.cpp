#include <iostream>
#include <cstdio>
#include <cstring>
int a[1005];
int main()
{
  int ans;
  int n;
  while (~scanf("%d", &n)) {
    memset(a, 0, sizeof(a));
    for (int i = 0; i <= n; i++) {
      int x;
      scanf("%d", &x);
      if (a[x])
        ans = x;
      a[x]++;
    }
    printf("%d\n", ans);
  }
}