#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m, mv;
int sx, sy;
char mp[105][105];
int vis[105][105];
int inq[105][105];
struct edge {
	int x, y;
	int mv;
	edge(int x, int y, int mv) : x(x), y(y), mv(mv) {}
};
bool check(int x, int y)
{
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (0 <= nx && nx < n && 0 <= ny && ny < m) {
			if (mp[nx][ny] == 'E') {
				return true;
			}
		}
	}
	return false;
}
void spfa()
{
  queue<pair<int, int> > que;
  que.push(make_pair(sx, sy));
  inq[sx][sy] = 1;
  vis[sx][sy] = m;
  while (que.size()) {
    pair<int, int> now = que.front();
    que.pop();
    if (vis[now.first][now.second])
      continue;
    int dis = vis[now.first][now.second];
    for (int i = 0; i < 4; i++) {
      int nx = now.first + dx[i], ny = now.second + dy[i];
      int ndis = vis[nx][ny];
      if (0 <= nx && nx < n && 0 <= ny && ny < m) {
        inq[sx][sy] = 0;
        char t = mp[nx][ny];
        if (t == 'E') {
          continue;
        }
        if (check(nx, ny)) {
          if (t != 'P' && t != '#' && t != 'Y') {
            mp[nx][ny] = '*';
          }
          vis[nx][ny] = 1e9;
          continue;
        }
        if (t == '.') {
          if (ndis < dis - 1 && dis >= 1) {
            vis[nx][ny] = dis - 1;
          }
          mp[nx][ny] = '*';
        } else if (t == 'T' && dis >= 2) {
          if (ndis < dis - 2) {
            vis[nx][ny] = dis - 2;
          }
          mp[nx][ny] = '*';
        } else if (t == 'R' && dis >= 3) {
          if (ndis < dis - 3) {
            vis[nx][ny] = dis - 3;
          }
          mp[nx][ny] = '*';
        } else if (t == '#') {
          ;
        } else if (t == 'P') {
          if (ndis < dis - 1 && dis >= 1) {
            vis[nx][ny] = dis - 1;
          }
        }
        if (inq[nx][ny])
          continue;
        inq[nx][ny] = 1;
        que.push(make_pair(nx, ny));
      }
    }
  }
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d %d", &n, &m, &mv);
		for (int i = 0; i < n; i++) {
			scanf("%s", mp[i]);
			for (int j = 0; j < m; j++) {
				if (mp[i][j] == 'Y') {
					sx = i, sy = j;
				}
			}
		}
		if (!check(sx, sy)) {
			spfa();
		}
		for (int i = 0; i < n; i++) {
			printf("%s\n", mp[i]);
		}
		printf("\n");
	}
	return 0;
}
