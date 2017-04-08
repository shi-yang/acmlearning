#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1000;
int a[maxn];
int main()
{
  int m, n, cas = 1;
  while (cin >> m >> n && m && n) {
    memset(a, 0, sizeof(a));
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      a[x] = 1;
    }
    int cnt = n * m + 1, up = 0, ans = 0;
    while (--cnt) {
      if (a[cnt]) {
        up++;
      } else {
        up--;
      }
      ans = max(ans, up);
    }
    printf("Case %d: %d\n", cas++, ans);
  }
  return 0;
}
