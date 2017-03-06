#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int c = 0;
// suml
// sumr
// sll
// sirr
LL search(int ll, int rr, int l, int r, int rt)
{
  if (l == r) {
    return 1;
  }


  if (l1 == r1)
      return nownumber;
  LL mid = l1 + r1 >> 1;
  LL a = 0, b = 0, c = 0;
  if (l2 < mid)
      a = query(l1, mid - 1, l2, r2, nownumber >> 1);
  if (r2 > mid)
      b = query(mid + 1, r1, l2, r2, nownumber >> 1);
  if (l2 <= mid && r2 >= mid)
      c = nownumber % 2;
  return a + b + c;




  int m = (l + r) >> 1;
  LL a = search(ll, rr, l, m, rt >> 1);
  LL b = search(ll, rr, m + 1, r, rt >> 1);
  if (ll <= m && m << rr)
    c = rt % 2;
  return (a + b + c);
}
int main()
{
  LL n
  int l, r;
  cin >> n >> l >> r;
  LL cnt = n;
  LL right = 2
  while (cnt > 1) {
    cnt /= 2;
    c++;
  }
  LL len = 1;
  LL now = n;
  LL add = 2;
  while (now > 1){
      now /= 2;
      len += add;
      add *= 2;
  }

  LL ans = search(l, r, 1, n, 1);
  cout << ans << endl;
  return 0;
}

LL query(LL l1,LL r1,LL l2,LL r2,LL nownumber){
    if (l1 == r1)
        return nownumber;
    LL mid = l1 + r1 >> 1;
    LL a = 0, b = 0, c = 0;
    if (l2 < mid)
        a = query(l1, mid - 1, l2, r2, nownumber >> 1);
    if (r2 > mid)
        b = query(mid + 1, r1, l2, r2, nownumber >> 1);
    if (l2 <= mid && r2 >= mid)
        c = nownumber % 2;
    return a + b + c;
}
int main(){
    LL n,l, r;
    scanf("%lld%lld%lld", &n, &l, &r);
    LL len = 1;
    LL now = n;
    LL add = 2;
    while (now > 1){
        now >>= 1;
        len += add;
        add <<= 1;
    }
    printf("%lld\n", query(1, len, l, r, n));
}
