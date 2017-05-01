#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005; 
int n, q;
int k;
int cnt[maxn << 2];


void build(int l, int r, int rt)
{
  if (l == r) {
    scanf("%d", &cnt[rt]);
  } else {
    int m = (l + r) >> 1;
    build(l, m, rt << 1);
    build(m + 1, r, rt << 1 | 1);
    if (m == l || m + 1 == r) {
      char s1[10], s2[10];
      sprintf(s1, "%d", cnt[rt << 1]);
      sprintf(s2, "%d", cnt[rt << 1 | 1]);
      cout << rt << ' ' << s1 << ' ' << s2 << endl;
      if (strlen(s1) == strlen(s2)) {
        cnt[rt] = 1;
      } else {
        cnt[rt] = 0;
      }
      return ;
    }
    cnt[rt] = cnt[rt << 1] + cnt[rt << 1 | 1];
  }
}
int query(int ll, int rr, int l, int r, int rt)
{
  if (l == r) {
    return 0;
  }
  if (ll <= l && r <= rr)
    return cnt[rt];
  int ret = 0;
  int m = (l + r) >> 1;
  if (ll <= m)
    ret += query(ll, rr, l, m, rt << 1);
  if (rr > m)
    ret += query(ll, rr, m + 1, r, rt << 1 | 1);
  return ret;
}
int main()
{
  while (~scanf("%d %d", &n, &q)) {
    build(1, n, 1);
    k = 0;
    while (q--) {
      int l, r;
      scanf("%d %d", &l, &r);
      //l = l + k, r = r - k;
      k = query(l, r, 1, n, 1);
      printf("%d\n", k);
    }
  }
  return 0;
}