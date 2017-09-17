#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int mi[N << 2];
void build(int l, int r, int rt)
{
  if (l == r) {
    scanf("%d", &mi[rt]);
    return;
  }
  int m = l + r >> 1;
  build(l, m, rt << 1);
  build(m + 1, r, rt << 1 | 1);
  mi[rt] = min(mi[rt << 1], mi[rt << 1 | 1]);
}
void update(int p, int v, int l, int r, int rt)
{
  if (l == r) {
    mi[rt] = v;
    return;
  }
  int m = l + r >> 1;
  if (p <= m)
    update(p, v, l, m, rt << 1);
  else
    update(p, v, m + 1, r, rt << 1 | 1);
  mi[rt] = min(mi[rt << 1], mi[rt << 1 | 1]);
}
int query(int ll, int rr, int l, int r, int rt) {
  if (ll <= l && r <= rr) {
    return mi[rt];
  }
  int m = l + r >> 1;
  int res = (int)1e9;
  if (ll <= m)
    res = min(res, query(ll, rr, l, m, rt << 1));
  if (rr > m)
    res = min(res, query(ll, rr, m + 1, r, rt << 1 | 1));
  return res;
}
int main()
{
  int n, q;
  scanf("%d %d", &n, &q);
  build(1, n, 1);
  while (q--) {
    char str[35];
    scanf("%s", str);
    vector<int> num;
    int v = 0;
    for (int i = 0; str[i]; i++) {
      if ('0' <= str[i] && str[i] <= '9') {
        v = v * 10 + str[i] - '0';
      } else {
        if (v)
          num.push_back(v);
        v = 0;
      }
    }
    if (str[0] == 'q') {
      printf("%d\n", query(num[0], num[1], 1, n, 1));
    } else {
      vector<int> tmp;
      for (int i = 0; i < num.size(); i++)
        tmp.push_back(query(num[i], num[i], 1, n, 1));
      for (int i = 1; i < num.size(); i++) {
        update(num[i - 1], tmp[i], 1, n, 1);
      }
      update(num[num.size() - 1], tmp[0], 1, n, 1);
    }
  }
  return 0;
}