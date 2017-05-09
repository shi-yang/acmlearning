#include <bits/stdc++.h>
using namespace std;
const int inf = 1e5;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, -1, 1};
int n, m;
const int maxn = 500;
char mp[33][33];
struct edge {
	int ix, iy;
	int ox, oy;
} e[100];
struct point {
	int x, y, c;
	point(){}
	point(int x, int y, int c) : x(x), y(y), c(c) {}
};
int bfs(int sx, int sy, int tx, int ty)
{
	if (sx == tx && sy == ty)
		return 0;
	queue<point> que;
	que.push(point(sx, sy, 0));
	int vis[33][33];
	memset(vis, 0, sizeof(vis));
	vis[sx][sy] = 1;
	while (que.size()) {
		point now = que.front();
		que.pop();
		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + now.x, ny = dy[i] + now.y;
			if (1 <= nx && nx <= n && 1 <= ny && ny <= n && !vis[nx][ny]) {
				if (mp[nx - 1][ny - 1] == '#')	continue;
				if (nx == tx && ny == ty)
					return now.c + 1;
				vis[nx][ny] = 1;
				que.push(point(nx, ny, now.c + 1));
			}
		}
	}
	return -1;
}
int dis[33][33];
int vis[33];
int cost;
int cnt;
int ans;
void dfs(int u)
{
	if (cnt == m)	{
		ans = min(cost, ans);
		return ;
	}
	for (int i = 0; i < m; i++) {
		if (vis[i])	continue;
		if (dis[u][i] == -1)	continue;
		cost += dis[u][i];
		vis[i]++;
		cnt++;
		dfs(i);
		cost -= dis[u][i];
		vis[i]--;
		cnt--;
	}
}
int main()
{
	while (~scanf("%d %d", &n, &m)) {
		for (int i = 0; i < n; i++)
			scanf("%s", mp[i]);
		for (int i = 0; i < m; i++) {
			scanf("%d %d %d %d", &e[i].ix, &e[i].iy, &e[i].ox, &e[i].oy);
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++) {
				if (i == j)	continue;
				dis[i][j] = bfs(e[i].ox, e[i].oy, e[j].ix, e[j].iy);
			}
		}
		ans = 1e6;
		for (int i = 0; i < m; i++) {
			memset(vis, 0, sizeof(vis));
			vis[i] = 1;
			cost = 0;
			cnt = 1;
			dfs(i);
		}
		if (ans != 1e6) {
			printf("%d\n", ans);
		} else {
			printf("-1\n");
		}
	}
	return 0;
}
