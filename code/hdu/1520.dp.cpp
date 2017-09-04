#include <bits/stdc++.h>
using namespace std;
const int N = 6005;
int a[N], f[N], dp[N];
vector<int> G[N];
int root(int x)
{
  return x == f[x] ? x : f[x] = root(f[x]);
}
void dfs(int x)
{
  for (int i = 0; i < G[x].size(); i++) {
    int v = G[x][i];
    dfs(v);
    dp[x] = max(dp[x]
  }
}
int main()
{
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    f[i] = i;
  }
  int l, k;
  while (~scanf("%d %d", &l, &k) && (l + k)) {
    G[k].push_back(l);
    f[l] = k;
  }
  int r = root(1);
  dfs(r);
  printf("%d\n", dp[r]);
  return 0;
}