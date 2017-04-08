#include <bits/stdc++.h>
using namespace std;
const int maxn = 30;
int g[maxn][maxn];
int vis[maxn];
int n, m;
int main()
{
  int cas = 1;
  while (cin >> n >> m, n + m) {
    int cnt = 0;
    memset(vis, 0, sizeof(vis));
    memset(g, 0, sizeof(g));
    for (int i = 0; i < maxn; i++) {
      g[i][i] = 1;
    }
    map<string, int> mp;
    map<int, string> st;
    for (int i = 0; i < m; i++) {
      string x, y;
      cin >> x >> y;
      if (!mp[x]) {
        mp[x] = ++cnt;
        st[cnt] = x;
      }
      if (!mp[y]) {
        mp[y] = ++cnt;
        st[cnt] = y;
      }
      g[mp[x]][mp[y]] = 1;
    }
    for (int k = 1; k <= n; k++) {
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
          g[i][j] |= g[i][k] & g[k][j];
        }
      }
    }
    if (cas != 1)
      cout << endl;
    printf("Calling circles for data set %d:\n", cas++);
    for (int i = 1; i <= n; i++) {
      if (!vis[i]) {
        cout << st[i];
        vis[i] = 1;
      } else {
        continue;
      }
      for (int j = 1; j <= n; j++) {
        if (!vis[j] && g[j][i] && g[i][j]) {
          cout << ", " << st[j];
          vis[j] = 1;
        }
      }
      cout << endl;
    }
  }
  return 0;
}
