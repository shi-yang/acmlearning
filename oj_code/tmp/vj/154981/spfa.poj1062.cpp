#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int maxn = 105;
int m, n;
int inq[maxn];
int d[maxn];
int level[maxn];
vector<pair<int, int> > e[maxn];
int spfa(int l, int r)
{
  for (int i = 1; i < maxn; i++)
    d[i] = 1e9, inq[i] = 0;
  queue<int> que;
  que.push(0);
  inq[0] = 1;
  d[0] = 0;
  while (!que.empty()) {
    int now = que.front();
    que.pop();
    for (int i = 0; i < e[now].size(); i++) {
      int v = e[now][i].first;
      if (level[v] < l || level[v] > r)
        continue;
      if (d[v] > d[now] + e[now][i].second) {
        d[v] = d[now] + e[now][i].second;
        if (inq[v])
          continue;
        inq[v] = 1;
        que.push(v);
      }
    }
    inq[now] = 0;
  }
  return d[1];
}
int main()
{
  cin >> m >> n;
  memset(level, 0, sizeof(level));
  for (int i = 1; i <= n; i++) {
    int p, l, x;
    cin >> p >> l >> x;
    e[0].push_back(make_pair(i, p));
    level[i] = l;
    while (x--) {
      int t, v;
      cin >> t >> v;
      //e[i].push_back(make_pair(t, v));
      e[t].push_back(make_pair(i, v));
    }
  }
  int ans = 1e9;
  for (int i = level[1] - m; i <= level[1]; i++)
    ans = min(ans, spfa(i, i + m));
  cout << ans << endl;
  return 0;
}
