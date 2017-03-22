#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 50000;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
int G[305][305];
int m;
int cnt;
int bfs()
{
  queue<pair<int, int> > que;
  que.push(make_pair(0, 0));
  while (!que.empty()) {
    pair<int, int> now = que.front();
    que.pop();
    for (int i = 0; i < 4; i++) {
      int nx = now.first + dx[i], ny = now.second + dy[i];
      if (0 <= nx && 0 <= ny && -(G[now.first][now.second] + 1) != G[nx][ny]) {
        G[nx][ny] = -(G[now.first][now.second] + 1);
      }
    }
  }
}
int main()
{
  while (cin >> m) {
    cnt = 0;
    for (int i = 0; i < m; i++) {
      int x, y, t;
      cin >> x >> y >> t;
      G[x][y] = t;
    }
    int ans = bfs();
    cout << ans << endl;
  }
  return 0;
}
