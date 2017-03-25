#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
vector<int> e[maxn];
int n;
int d[maxn];
int vis[maxn];
int bfs(int s)
{
  int color = 0;
  queue<int> que;
  que.push(s);
  while (!que.empty()) {
    int now = que.front();
    que.pop();
    int cnt = 0;
    for (int i = 0; i < e[now].size(); i++) {
      for (int j = 0; j < e[i].size(); j++) {
        if (e[i][j] == now || vis[now]) {
          vis[now] = 1; continue;
        }
        color++;
      }
    }
  }
  return color;
}
int main()
{
  cin >> n;
  memset(d, 0, sizeof(d));
  memset(vis, 0, sizeof(vis));
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    e[x].push_back(y);
    e[y].push_back(x);
  }
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    sum += bfs(i);
  }
  cout << sum << endl;
  return 0;
}