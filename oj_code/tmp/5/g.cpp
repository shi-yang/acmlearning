#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 25;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int m[25][25];
int w, h;
int sx, sy;
int ex, ey;
int dfs(int x, int y, int t, int cnt)
{
	if (x == ex && y == ey)
		return cnt;
	if (cnt == 9)
		return 0;
	for (int i = 0; i < 4; i++) {
		if (t != -1)
			i = t;
		int nx = x + dx[i], ny = y + dy[i];
		if (0 <= nx && nx < h && 0 <= ny && ny < w) {
			if (m[nx][ny] == 1) {
				m[nx][ny] = 0;
				dfs(nx, ny, -1, cnt + 1);
				m[nx][ny] = 1;
			} else {
				dfs(nx, ny, i, cnt + 1);
			}
		}
		it (t != -1)
			break;
	}
	return 0;
}
int main()
{
	while (cin >> w >> h) {
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
		dfs(sx, sy, -1, 0);
	}
	return 0;
}
