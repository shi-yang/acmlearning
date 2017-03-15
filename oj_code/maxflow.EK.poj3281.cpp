#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int maxn = 405;
int start = 0;
int ed = 401;
int path[maxn];
int mp[maxn][maxn];
int n, f, d;
bool bfs(int s, int t)
{
  queue<int> que;
  que.push(s);
  memset(path, -1, sizeof(path));
  path[s] = s;
  while (!que.empty()) {
    int q = que.front();
    que.pop();
    for (int i = 1; i < maxn; i++) {
      if (mp[q][i] > 0 && path[i] == -1) {
        path[i] = q;
        if (i == ed)
          return true;
        que.push(i);
      }
    }
  }
  return false;
}
int main()
{
  cin >> n >> f >> d;
  memset(mp, 0, sizeof(mp));
  for (int i = 1; i <= n; i++) {
    int x, y, t;
    cin >> x >> y;
    while (x--) {
      cin >> t;
      mp[start][t] = 1; // s-f
      mp[t][100 + i] = 1; // f-c1
    }
    while (y--) {
      cin >> t;
      mp[200 + i][t + 300] = 1; // c2-d
      mp[t + 300][ed] = 1; // d-end
    }
    mp[100 + i][200 + i] = 1; // c1-c2
  }
  int ans = 0;
  while (bfs(start, ed)) {
    for (int i = ed; i != start; i = path[i]) {
      mp[path[i]][i]--;
      mp[i][path[i]]++;
    }
    ans++;
  }
  cout << ans << endl;
  return 0;
}
