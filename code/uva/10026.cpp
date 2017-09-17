#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
struct edge {
  int t, c, id;
  bool operator < (const edge &a) const {
    return c * a.t  > a.c * t || c * a.t == a.c * t && id < a.id;
  }
} e[N];
int main()
{
  int n, t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d %d", &e[i].t, &e[i].c);
      e[i].id = i + 1;
    }
    sort(e, e + n);
    for (int i = 0; i < n; i++) {
      printf("%d", e[i].id);
      if (i != n - 1)
        putchar(' ');
    }
    puts("");
    if (t)
      puts("");
  }
  return 0;
}