#include <bits/stdc++.h>
using namespace std;
const int N = 205;
vector<int> G[N];
int n, m;
bool ok;
int color[N];
void dfs(int x, int c)
{
  color[x] = c;
  for (auto v : G[x]) {
    if (!color[v]) {
      dfs(v, 3 - c);
    } else if (color[v] != 3 - c) {
      ok = false;
      return;
    }
  }
}
int main()
{
  while (~scanf("%d", &n) && n) {
    scanf("%d", &m);
    for (int i = 0; i < n; i++) {
      G[i].clear();
    }
    for (int i = 0; i < m; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      G[u].push_back(v);
      G[v].push_back(u);
    }
    ok = true;
    memset(color, 0, sizeof(color));
    dfs(1, 1);
    if (ok) {
      printf("BICOLORABLE.\n");
    } else {
      printf("NOT BICOLORABLE.\n");
    }
  }
  return 0;
}