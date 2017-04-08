#include <bits/stdc++.h>
using namespace std;
const int maxn = 150005;
int f[maxn], cnt[maxn], sum[maxn];
int root(int x)
{
  return x == f[x] ? x : f[x] = root(f[x]);
}
int main()
{
  int n, m;
  memset(cnt, 0, sizeof(cnt));
  memset(sum, 0, sizeof(sum));
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++)
    f[i] = i;
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    if (root(a) != root(b)) {
      f[root(a)] = root(b);
    }
    cnt[a]++; cnt[b]++;
  }
  int num = 0;
  for (int i = 1; i <= n; i++) {
    sum[root(i)]++;
  }
  int ok = 1;
  for (int i = 1; i <= n; i++) {
    if (sum[root(i)] != cnt[i] + 1) {
      ok = 0;
      break;
    }
  }
  if (ok) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }
  return 0;
}
