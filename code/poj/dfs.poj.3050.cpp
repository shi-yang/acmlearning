#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int tx[4] = {-1, 1, 0, 0};
int ty[4] = {0, 0, -1, 1};
int map[5][5];
int ans, cnt, vis[1000000];
char tmp[7];
void dfs(int x, int y)
{
	if (cnt == 6) {
		int t;
		sscanf(tmp, "%d", &t);
		if (!vis[t]) {
			ans++;
			vis[t] = 1;
		}
		return ;
	}
	tmp[cnt] = map[x][y] + '0';
	for (int i = 0; i < 4; i++) {
		int nx = x + tx[i], ny = y + ty[i];
		if (0 <= nx && nx < 5 && 0 <= ny && ny < 5) {
			cnt++;
			dfs(nx, ny);
			cnt--;
		}
	}
}

int main()
{
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> map[i][j];
		}
	}
	ans = 0;
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cnt = 0;
			dfs(i, j);
		}
	}
	cout << ans << endl;
	return 0;
}
