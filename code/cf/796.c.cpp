#include <bits/stdc++.h>
using namespace std;
const int maxn = 300005;
int a[maxn];
vector<int> G[maxn];
int main()
{
  int n;
  scanf("%d", &n);
  int mx = -1e9;
  for (int i = 0; i < n; i++)
    scanf("%d", a + i), mx = max(mx, a[i]);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }
  int mxcnt = 0;  
  int pos;
  int mscnt = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == mx)
      mxcnt++, pos = i;
    if (a[i] == mx - 1)
      mscnt++;
  }
  pos++;
  int ans;
  if (mxcnt == 1) {
    int cnt = 0;
    for (int i = 0; i < G[pos].size(); i++) {
      int now = G[pos][i] - 1;
      if (a[now] == mx - 1) {
        cnt++;
      }
    }
    if (cnt == mscnt) {
      ans = mx;
    } else {
      ans = mx + 1;
    }
  } else {
    int cnt, f = 0;
    ans = mx + 1;
    for (int i = 1; i <= n; i++) {
      cnt = 0;
      for (int j = 0; j < G[i].size(); j++) {
        if (a[G[i][j] - 1] == mx) {
          cnt++;
        }
      }
      if (cnt == mxcnt || cnt == mxcnt - 1 && a[i - 1] == mx) {
        f = 1;
        break;
      }
    }
    if (!f)
      ans++;
  }
  printf("%d\n", ans);
  return 0;
}