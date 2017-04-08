#include <iostream>
#include <cstdio>
const int maxn = 100001;
int a[maxn];
int n, q;
int lowbit(int x)
{
  return x & (-x);
}
int add(int x, int v)
{
  while (x <= n) {
    a[x] += v;
    x += lowbit(x);
  }
}
int sum(int x)
{
  int sum = 0;
  while (x > 0) {
    sum += a[x];
    x -= lowbit(x);
  }
  return sum;
}
int main()
{
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; i++) {
    a[i] = 0;
  }
  for (int i = 0; i < q; i++) {
    int x, p;
    scanf("%d %d", &x, &p);
    add(x, p);
    int ans = sum(n);
    printf("%d\n", ans % 10007);
  }
  return 0;
}
