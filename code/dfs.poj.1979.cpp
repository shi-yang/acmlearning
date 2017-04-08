#include <iostream>
#include <cstdio>
using namespace std;
const int maxn  = 22;
char map[maxn][maxn];
int tx[4] = {0, 0, -1, 1};
int ty[4] = {-1, 1, 0, 0};
int n, m;
int ans;
void dfs(int x, int y) {
	ans++;
	map[x][y] = '#';
	for (int i = 0; i < 4; i++) {
		int nx = x + tx[i], ny = y + ty[i];
		if (0 <= nx && nx < n && 0 <= ny && ny < m && map[nx][ny] == '.') {
			dfs(nx, ny);
		}
	}
}
int main()
{
	while (scanf("%d%d", &m, &n) && n && m) {
		int sx, sy;
		for (int i = 0; i < n; i++) {
			cin >> map[i];
			for (int j = 0; j < m; j++) {
				if (map[i][j] == '@') {
					sx = i, sy = j;
				}
			}
		}
		ans = 0;
		dfs(sx, sy);
		cout << ans << endl;
	}
	return 0;
}
