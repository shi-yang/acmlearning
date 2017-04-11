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
void bfs()
{
	memset(vis, 0, sizeof(vis));
	queue<edge> que;
	que.push(edge(sx, sy, mv));
	vis[sx][sy] = mv;
	while (que.size()) {
		edge now = que.front();
		que.pop();
		if (now.mv == 0) {
			continue;
		}
		for (int i = 0; i < 4; i++) {
			int nx = now.x + dx[i], ny = now.y + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				char t = mp[nx][ny];
				if (t == 'E') {
					continue;
				}
				if (check(nx, ny)) {
					if (t != 'P' && t != '#' && t != 'Y')
						mp[nx][ny] = '*';
					continue;
				}
				if (t == '.') {
					if (vis[nx][ny] < now.mv - 1) {
						que.push(edge(nx, ny, now.mv - 1));
						vis[nx][ny] = now.mv - 1;
					}
					mp[nx][ny] = '*';
				} else if (t == 'T' && now.mv >= 2) {
					if (vis[nx][ny] < now.mv - 2) {
						que.push(edge(nx, ny, now.mv - 2));
						vis[nx][ny] = now.mv - 2;
					}
					mp[nx][ny] = '*';
				} else if (t == 'R' && now.mv >= 3) {
					if (vis[nx][ny] < now.mv - 3) {
						que.push(edge(nx, ny, now.mv - 3));
						vis[nx][ny] = now.mv - 3;
					}
					mp[nx][ny] = '*';
				} else if (t == '#') {
					;
				} else if (t == 'P') {
					if (vis[nx][ny] < now.mv - 1) {
						que.push(edge(nx, ny, now.mv - 1));
						vis[nx][ny] = now.mv - 1;
					}
				}
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
			bfs();
		}
		for (int i = 0; i < n; i++) {
			printf("%s\n", mp[i]);
		}
		printf("\n");
	}
	return 0;
}
