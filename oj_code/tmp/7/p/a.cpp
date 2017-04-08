#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 50005;
int f[maxn], cnt[maxn];
int n, m;
int root(int x)
{
  return x == f[x] ? x : f[x] = root(f[x]);
}
int main()
{
  int kase = 1;
  while (~scanf("%d %d", &n, &m) && (m + n)) {
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= n; i++) {
      f[i] = i;
    }
    for (int i = 0; i < m; i++) {
      int a, b;
      scanf("%d %d", &a, &b);
      if (root(a) != root(b)) {
        f[root(a)] = root(b);
      }
    }
    for (int i = 1; i <= n; i++) {
      if (cnt[root(i)] == 0) {
        cnt[root(i)] = 1;
      }
    }
    int sum = 0;
    for (int i = 1; i <= n; i++) {
      sum += cnt[i];
    }
    printf("Case %d: %d\n", kase++, sum);
  }
  return 0;
}
