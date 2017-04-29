#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 10005;
int col[maxn << 4];
int has[maxn];
int x[maxn << 2];
struct edge {
  int l, r;
}e[maxn];
void update(int ll, int rr, int c, int l, int r, int rt) {
  if (ll <= l && r <= rr) {
    col[rt] = c;
    return ;
  }
  if (col[rt] != -1) {
    col[rt << 1] = col[rt << 1 | 1] = col[rt];
    col[rt] = -1;
  }
  int m = (l + r) >> 1;
  if (ll <= m)
    update(ll, rr, c, l, m, rt << 1);
  if (rr > m)
    update(ll, rr, c, m + 1, r, rt << 1 | 1);
}
int ans;
void query(int l, int r, int rt)
{
  if (col[rt] != -1) {
    if (!has[col[rt]])
      ans++;
    has[col[rt]] = 1;
    return ;
  }
  if (l == r)
    return;
  int m = (l + r) >> 1;
  query(l, m, rt << 1);
  query(m + 1, r, rt << 1 | 1);
}
int main()
{
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d %d", &e[i].l, &e[i].r);
      x[cnt++] = e[i].l;
      x[cnt++] = e[i].r;
    }
    sort(x, x + cnt);
    int m = 1;
    for (int i = 1; i < cnt; i++) {
      if (x[i] != x[i - 1]) 
        x[m++] = x[i];
    }
    for (int i = m - 1; i > 0; i--) {
      if (x[i] != x[i - 1] + 1)
        x[m++] = x[i - 1] + 1;
    }
    sort(x, x + m);
    memset(has, 0, sizeof(has));
    memset(col, -1, sizeof(col));
    ans = 0;
    for (int i = 0; i < n; i++) {
      int l = lower_bound(x, x + m, e[i].l) - x;
      int r = lower_bound(x, x + m, e[i].r) - x;
      update(l, r, i, 0, m, 1);
    }
    query(0, m, 1);
    printf("%d\n", ans);
  }
  return 0;
}