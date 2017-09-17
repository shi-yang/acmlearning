#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
struct line {
  int l, r;
  bool operator < (const line &op) const {
    return l < op.l || l == op.l && r > op.r;
  }
} e[N], ans[N];
int main()
{
  int t;
  scanf("%d", &t);
  for (int cas = 0; cas < t; cas++) {
    if (cas)
      puts("");
    int m;
    scanf("%d", &m);
    int n = 0;
    while (~scanf("%d %d", &e[n].l, &e[n].r)) {
      if (e[n].l == 0 && e[n].r == 0)
        break;
      n++;
    }
    sort(e, e + n);
    int l = 0, cnt = 0;
    for (int i = 0; i < n && l < m;) {
      int r = -1, p;
      while (e[i].l <= l && i < n) {
        if (r < e[i].r) {
          p = i;
          r = e[i].r;
        }
        i++;
      }
      if (r == -1) {
        break;
      }
      l = r;
      ans[cnt++] = e[p];
    }  
    if (l < m) {
      printf("0\n");
      continue;
    }
    printf("%d\n", cnt);
    for (int i = 0; i < cnt; i++) {
      printf("%d %d\n", ans[i].l, ans[i].r);
    }
  }
  return 0;
}