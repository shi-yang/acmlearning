#include <bits/stdc++.h>
using namespace std;
int n, x;
const int maxn = 10005;
int pos;
int rcd[maxn << 2];
void inparse(int rt)
{
  if (rt > n)
    return ;
  inparse(rt * 2);
  rcd[pos++] = rt;
  inparse(rt * 2 + 1);
}
int main()
{
  int t;
  scanf("%d", &t);
  for (int kas = 1; kas <= t; kas++) {
    scanf("%d %d", &n, &x);
    pos = 1;
    inparse(1);
    printf("Case #%d: %d\n", kas, rcd[x]);
  }
  return 0;
}