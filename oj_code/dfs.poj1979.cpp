#include <iostream>
using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
int w, h;
char m[25][25];
int ans;
void dfs(int x, int y)
{
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i], ny = y + dy[i];
    if (0 <= nx && nx < h && 0 <= ny & ny < w && m[nx][ny] == '.') {
      ans++;
      m[nx][ny] = '#';
      dfs(nx, ny);
    }
  }
}
int main()
{
  while (cin >> w >> h, w + h) {
    int sx, sy;
    ans = 1;
    for (int i = 0; i < h; i++) {
      cin >> m[i];
      for (int j = 0; j < w; j++)
        if (m[i][j] == '@')
          sx = i, sy = j;
    }
    dfs(sx, sy);
    cout << ans << endl;
  }
  return 0;
}
