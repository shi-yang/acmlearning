#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
const int N = 100005;
struct edge {
  i64 sum;
  bool flag;
} e[N << 2];
void build(int l, int r, int rt)
{
  if (l == r) {
    scanf("%lld", &e[rt].sum);
    e[rt].flag = (e[rt].sum == 1) ? 1 : 0;
  } else {
    int m = l + r >> 1;
    build(l, m, rt << 1);
    build(m + 1, r, rt << 1 | 1);
    e[rt].sum = e[rt << 1].sum + e[rt << 1 | 1].sum;
    e[rt].flag = e[rt << 1].flag & e[rt << 1 | 1].flag;
  }
}
void update(int ll, int rr, int l, int r, int rt)
{
  if (e[rt].flag) {
    return;
  }
  if (l == r) {
    e[rt].sum = (int) sqrt(1.0 * e[rt].sum);
    e[rt].flag = (e[rt].sum == 1) ? 1 : 0;
    return;
  }
  int m = l + r >> 1;
  if (ll <= m)
    update(ll, rr, l, m, rt << 1);
  if (rr > m)
    update(ll, rr, m + 1, r, rt << 1 | 1);
  e[rt].sum = e[rt << 1].sum + e[rt << 1 | 1].sum;
  e[rt].flag = e[rt << 1].flag & e[rt << 1 | 1].flag;
}
i64 query(int ll, int rr, int l, int r, int rt)
{
  if (ll <= l && r <= rr) {
    return e[rt].sum;
  }
  i64 res = 0;
  int m = l + r >> 1;
  if (ll <= m)
    res += query(ll, rr, l, m, rt << 1);
  if (rr > m)
    res += query(ll, rr, m + 1, r, rt << 1 | 1);
  return res;
}
int main()
{
  int n, cas = 1;
  while (~scanf("%d", &n)) {
    printf("Case #%d:\n", cas++);
    build(1, n, 1);
    int m;
    scanf("%d", &m);
    while (m--) {
      int a, x, y;
      scanf("%d %d %d", &a, &x, &y);
      if (x > y)
        swap(x, y);
      if (a) {
        printf("%lld\n", query(x, y, 1, n, 1));
      } else {
        update(x, y, 1, n, 1);
      }
    }
    puts("");
  }
  return 0;
}