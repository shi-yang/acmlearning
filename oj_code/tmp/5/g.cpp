#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int maxn = 25;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int m[25][25];
int w, h;
int sx, sy;
int ex, ey;
struct edge {
  int x, y, t, d;
};                           
int bfs()
{
  queue<edge> que;
  que.push(edge{sx, sy, -1, 0});
  while (que.size()) {
    edge now = que.front();
    if (now.x == ex && now.y == ey)
      return now.d;
    que.pop();
    for (int i = 0; i < 4; i++) {
      if (now.t != -1)
        i = now.t;
      int tmp = (now.t == -1);
      int nx = now.x + dx[i], ny = now.y + dy[i];
      if (0 <= nx && nx < h && 0 <= ny && ny < w) {
        if (m[nx][ny] != 1) {
          que.push(edge{nx, ny, i, now.d + tmp});
        } else {
          que.push(edge{nx, ny, -1, now.d + tmp});
        }
      }
      if (now.t != -1)
        break;
    }
  }
  return -1;
}
int main()
{
  while (cin >> w >> h, w + h) {
    memset(m, 0, sizeof(m));
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        cin >> m[i][j];
        if (m[i][j] == 2)
          sx = i, sy = j;
        if (m[i][j] == 3)
          ex = i, ey = j;
      }
    }     
    cout << bfs() << endl;
  }
  return 0;
}
