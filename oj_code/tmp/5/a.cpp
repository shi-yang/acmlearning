#include <iostream>
#include <cstring>
#include <queue>
#include <cstdio>
using namespace std;
int m[10][10];
int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[] = {1, -1, 2, -2, 2, -2, 1, -1};
string a, b;
void bfs()
{
  memset(m, -1, sizeof(m));
  int sx = a[0] - 'a', sy = a[1] - '0';
  int ex = b[0] - 'a', ey = b[1] - '0';
  m[sx][sy] = 0;
  queue<pair<int, int> > que;
  que.push(make_pair(sx, sy));
  while (!que.empty()) {
    pair <int, int> now = que.front();
    que.pop();
    for (int i = 0; i < 8; i++) {
      int nx = now.first + dx[i], ny = now.second + dy[i];
      if (0 <= nx && nx < 8 && 0 < ny && ny <= 8 && m[nx][ny] == -1) {
        m[nx][ny] = m[now.first][now.second] + 1;
        if (nx == ex && ny == ey)
          return;
        que.push(make_pair(nx, ny));
      }
    }
  }
}
int main()
{
  while (cin >> a >> b) {
    bfs();
    cout << "To get from " << a << " to " << b << " takes " << m[b[0] - 'a'][b[1] - '0'] << " knight moves." << endl;
    //printf("To get from %s to %s takes %d knight moves.\n", a.c_str(), b.c_str(), m[b[0] - 'a'][b[1] - '0']);
  }
  return 0;
}
