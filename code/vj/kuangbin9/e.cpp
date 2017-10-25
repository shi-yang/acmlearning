#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 1005;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
char mp[N][N];
int fire[N][N], walk[N][N];
int sx, sy;
int c, r;
void bfs1()
{
	memset(fire, INF, sizeof(fire));
	queue<pair<int, int> > que;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (mp[i][j] == 'F') {
				fire[i][j] = 0;
				que.push(make_pair(i, j));
			}
		}
	}
	while (!que.empty()) {
		auto u = que.front();
		que.pop();
		for (int i = 0; i < 4; i++) {
			int nx = u.first + dx[i], ny = u.second + dy[i];
			if (0 <= nx && nx < r && 0 <= ny && ny < c) {
				if (mp[nx][ny] == '#' || fire[nx][ny] != INF) {
					continue;
				}
				fire[nx][ny] = fire[u.first][u.second] + 1;
				que.push(make_pair(nx, ny));
			}
		}
	}
}
int bfs2()
{
	memset(walk, -1, sizeof(walk));
	queue<pair<int, int> > que;
	que.push(make_pair(sx, sy));
	walk[sx][sy] = 0;
	while (!que.empty()) {
		auto u = que.front();
		que.pop();
		for (int i = 0; i < 4; i++) {
			int nx = u.first + dx[i], ny = u.second + dy[i];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c) {
				return walk[u.first][u.second] + 1;
			}
			if (mp[nx][ny] == '#' || walk[nx][ny] != -1)
				continue;
			if (walk[u.first][u.second] + 1 >= fire[nx][ny])
				continue;
			walk[nx][ny] = walk[u.first][u.second] + 1;
			que.push(make_pair(nx, ny));
		}
	}
	return -1;
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &r, &c);
		for (int i = 0; i < r; i++) {
			scanf("%s", mp[i]);
			for (int j = 0; j < c; j++) {
				if (mp[i][j] == 'J') {
					sx = i, sy = j;
				}
			}
		}
		bfs1();
		int ans = bfs2();
		if (ans == -1) {
			puts("IMPOSSIBLE");
		} else {
			printf("%d\n", ans);
		}
	}
	return 0;
}