#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int N = 6005;
int v[N];
int f[N], n, dp[N][2];
vector<int> G[N];
void dfs(int u)
{
  dp[u][1] = v[u];
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i];
    if (f[u] == v)
      continue;
    dfs(v);
    dp[u][1] += dp[v][0];
    dp[u][0] += max(dp[v][1], dp[v][0]);
  }
}
int main()
{
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", v + i);
    f[i] = i;
  }
  int l, k;
  while (~scanf("%d %d", &l, &k), l + k > 0) {
    f[l] = k;
    G[k].push_back(l);
  }
  int root = 1;
  while (f[root] != root)
    root = f[root];
  dfs(root);
  printf("%d\n", max(dp[root][0], dp[root][1]));
  return 0;
}