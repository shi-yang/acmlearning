#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int maxn = 50000;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
int G[305][305];
int vis[305][305];
int m;
struct edge {
  int x, y, t;
  edge(int xx, int yy, int tt) : x(xx), y(yy), t(tt) {}
};
int bfs()
{
  if (G[0][0] == -1)
    return 0;
  if (G[0][0] == 0)
    return -1;
  queue<edge> que;
  que.push(edge(0, 0, 0));
  while (!que.empty()) {
    edge now = que.front();
    cout << "x: " << now.x << " y:" << now.y << endl;
    que.pop();
    for (int i = 0; i < 4; i++) {
      int nx = now.x + dx[i], ny = now.y + dy[i];
      if (0 <= nx && nx <= 300 && 0 <= ny && ny <= 300) {
        if (G[nx][ny] == -1)
          return now.t + 1;
        if (now.t < G[nx][ny]) {
          que.push(edge(nx, ny, now.t + 1));
          G[nx][ny] = now.t + 1;
        }
      }
    }
  }
  return -1;
}
int main()
{                                       
  while (cin >> m) {
    memset(G, -1, sizeof(G));
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < m; i++) {
      int x, y, t;
      cin >> x >> y >> t;
      G[x][y] == -1 ? G[x][y] = t : G[x][y] = min(G[x][y], t);
      for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (0 <= nx && 0 <= ny) {
          G[nx][ny] == -1 ? G[nx][ny] = t : G[nx][ny] = min(G[nx][ny], t);
        }
      }
    }
    int ans = bfs();
    cout << ans << endl;
  }
  return 0;
}
