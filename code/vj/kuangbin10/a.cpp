#include <bits/stdc++.h>
using namespace std;
const int N = 10;
vector<int> G[N];
int link[N], vis[N];
int x, y;
bool dfs(int u)
{
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i];
    if (!vis[v]) {
      vis[v] = 1;
      if (link[v] == -1 || dfs(link[v])) {
        link[v] = u;
        return true;
      }
    }
  }
  return false;
}
int main()
{
  int n;
  char mp[5][5];
  int col[5][5], row[5][5];
  while (~scanf("%d", &n) && n) {
    for (int i = 0; i < N; i++)
      G[i].clear();
    for (int i = 0; i < n; i++) {
      scanf("%s", mp[i]);
    }
    memset(col, -1, sizeof(col));
    memset(row, -1, sizeof(row));
    x = 0, y = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (mp[i][j] == '.' && col[i][j] == -1) {
          for (int k = j; k < n && mp[i][k] == '.'; k++) {
            col[i][k] = x;
          }
          ++x;
        }
        if (mp[j][i] == '.' && row[j][i] == -1) {
          for (int k = j; k < n && mp[k][i] == '.'; k++) {
            row[k][i] = y;
          }
          ++y;
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (mp[i][j] == '.')
          G[row[i][j]].push_back(col[i][j]);
      }
    }
    memset(link, -1, sizeof(link));
    int ans = 0;
    for (int i = 0; i < y; i++) {
      memset(vis, 0, sizeof(vis));
      ans += dfs(i);
    }
    printf("%d\n", ans);
  }
  return 0;
}