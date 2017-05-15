#include <iostream>
#include <cstdio>
const int maxn = 100005;
int n, q;
long long sum[maxn << 2];
long long col[maxn << 2];
void pushdown(int rt, int num)
{
  if (col[rt]) {
    col[rt << 1] += col[rt];
    col[rt << 1 | 1] += col[rt];
    sum[rt << 1] += (num - (num >> 1)) * col[rt];
    sum[rt << 1 | 1] += (num >> 1) * col[rt];
    col[rt] = 0;
  }
}
void build(int l, int r, int rt)
{
  if (l == r) {
    scanf("%lld", &sum[rt]);
  } else {
    int m = (l + r) >> 1;
    build(l, m, rt << 1);
    build(m + 1, r, rt << 1 | 1);
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
  }
}
void update(int ll, int rr, long long v, int l, int r, int rt)
{
  if (ll <= l && r <= rr) {
    sum[rt] += (long long) v * (r - l + 1);
    col[rt] += v;
    return ;
  }
  pushdown(rt, r - l + 1);
  int m = (l + r) >> 1;
  if (ll <= m)
    update(ll, rr, v, l, m, rt << 1);
  if (rr > m)
    update(ll, rr, v, m + 1, r, rt << 1 | 1);
  sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}
long long query(int ll, int rr, int l, int r, int rt)
{
  if (ll <= l && r <= rr) {
    return sum[rt];
  }
  pushdown(rt, r - l + 1);
  int m = (l + r) >> 1;
  long long res = 0;
  if (ll <= m)
    res += query(ll, rr, l, m, rt << 1);
  if (rr > m)
    res += query(ll, rr, m + 1, r, rt << 1 | 1);
  return res;
}
int main()
{
  scanf("%d", &n);
  build(1, n, 1);
  scanf("%d", &q);
  while (q--) {
    int l, r;
    long long v;
    scanf("%d %d %lld", &l, &r, &v);
    update(l, r, v, 1, n, 1);
    long long ans = query(l, r, 1, n, 1);
    printf("%lld\n", ans);
  }
  return 0;
}