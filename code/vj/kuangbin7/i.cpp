#include <iostream>
#include <stack>
#include <cstdio>
using namespace std;
const int N = 50005;
struct node {
  int l, r, m;
} e[N << 2];
void build(int l, int r, int rt)
{
  if (l == r) {
    e[rt].l = e[rt].r = e[rt].m = 1;
    return;
  }
  int m = l + r >> 1;
  build(l, m, rt << 1);
  build(m + 1, r, rt << 1 | 1);
  e[rt].r = e[rt].l = e[rt].m = r - l + 1;
}
void update(int p, int v, int l, int r, int rt)
{
  if (l == r) {
    e[rt].l = e[rt].r = e[rt].m = v;
    return;
  }
  int m = l + r >> 1;
  if (p <= m)
    update(p, v, l, m, rt << 1);
  if (p > m)
    update(p, v, m + 1, r, rt << 1 | 1);
  e[rt].l = e[rt << 1].l;
  e[rt].r = e[rt << 1 | 1].r;
  e[rt].m = max(max(e[rt << 1].m, e[rt << 1 | 1].m), e[rt << 1].r + e[rt << 1 | 1].l);
  if (e[rt << 1].l == m - l + 1) {
    e[rt].l += e[rt << 1 | 1].l;
  }
  if (e[rt << 1 | 1].r == r - (m + 1) + 1) {
    e[rt].r += e[rt << 1].r;
  }
}
int query(int p, int l, int r, int rt)
{
  if (l == r || e[rt].m == r - l + 1 || e[rt].m == 0) {
    return e[rt].m;
  }
  int m = l + r >> 1;
  if (p <= m) {
    if (p >= m - e[rt << 1].r + 1)
      return e[rt << 1].r + e[rt << 1 | 1].l;
    else
      return query(p, l, m, rt << 1);
  } else {
    if (p <= m + 1 + e[rt << 1 | 1].l - 1)
      return e[rt << 1].r + e[rt << 1 | 1].l;
    else
      return query(p, m + 1, r, rt << 1 | 1);
  }
}
int main()
{
  int n, m;
  while (~scanf("%d %d", &n, &m)) {
    build(1, n, 1);
    stack<int> s;
    while (m--) {
      char c[5];
      int x;
      scanf("%s", c);
      if (c[0] == 'D') {
        scanf("%d", &x);
        s.push(x);
        update(x, 0, 1, n, 1);
      } else if (c[0] == 'Q') {
        scanf("%d", &x);
        printf("%d\n", query(x, 1, n, 1));
      } else {
        update(s.top(), 1, 1, n, 1);
        s.pop();
      }
    }
  }
  return 0;
}