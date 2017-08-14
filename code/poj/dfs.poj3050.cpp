#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int vis[1000000];
int m[10][10];
int cnt, ans;
char tmp[10];
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
void dfs(int x, int y)
{
  tmp[cnt] = m[x][y] + '0';
  if (cnt == 5) {
    int a;
    sscanf(tmp, "%d", &a);
    if (!vis[a]) {
      ans++;
      vis[a] = 1;
    }
    return;
  }
  for (int i = 0; i < 4; i++) {
    int nx = dx[i] + x, ny = dy[i] + y;
    if (0 <= nx && nx < 5 && 0 <= ny && ny < 5) {
      cnt++;
      dfs(nx, ny);
      cnt--;
    }
  }
}

int main()
{
  ans = 0;
  memset(vis, 0, sizeof(vis));
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++)
      cin >> m[i][j];
  }
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      cnt = 0;
      dfs(i, j);
    }
  }
  cout << ans << endl;
  return 0;
}
