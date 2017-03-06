#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int maxn = 205;
const int inf = 1e9;
int mp[maxn][maxn];
int path[maxn];
int n, m;
bool bfs(int s, int t)
{
  queue<int> que;
  que.push(s);
  memset(path, -1, sizeof(path));
  path[s] = s;
  while (!que.empty()) {
    int q = que.front();
    que.pop();
    for (int i = 1; i <= m; i++) {
      if (mp[q][i] > 0 && path[i] == -1) {
        path[i] = q;
        if (i == t) {
          return true;
        }
        que.push(i);
      }
    }
  }
  return false;
}
int ek(int s, int t)
{
  int flow = 0;
  while (bfs(s, t)) {
    int d = inf;
    for (int i = t; i != s; i = path[i]) {
      d = min(d, mp[path[i]][i]);
    }
    for (int i = t; i != s; i = path[i]) {
      mp[path[i]][i] -= d;
      mp[i][path[i]] += d;
    }
    flow += d;
  }
  return flow;
}
int main()
{
  while (cin >> n >> m) {
    memset(mp, 0, sizeof(mp));
    for (int i = 0; i < n; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      mp[a][b] += c;
    }
    int ans = ek(1, m);
    cout << ans << endl;
  }
  return 0;
}
