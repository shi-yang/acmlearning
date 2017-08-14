#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int a[50005], n;
int lowbit(int k)
{
  return k & (-k);
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
  int t;
  scanf("%d", &t);
  int cas = 1;
  while (t--) {
    scanf("%d", &n);
    memset(a, 0, sizeof(a));
		printf("Case %d:\n", cas++);
    for (int i = 1; i <= n; i++) {
      int x;
      scanf("%d", &x);
      add(i, x);
    }
    char str[10];
    while (~scanf("%s", str)) {
			if (str[0] == 'E') {
				break;
			} else {
        int p, q;
				scanf("%d %d", &p, &q);
				if (str[0] == 'Q') {
					int ans = sum(q) - sum(p - 1);
					printf("%d\n", ans);
				} else if (str[0] == 'A') {
					add(p, q);
				} else if (str[0] == 'S') {
					add(p, -q);
				}
			}
		}
  }
  return 0;
}
