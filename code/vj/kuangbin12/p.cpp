#include <bits/stdc++.h>
using namespace std;
const int N = 105;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {1, -1, 0, 0};
int a[N][N];
int dp[N][N];
int n, k;
int dfs(int x, int y)
{
	if (dp[x][y])
		return dp[x][y];
	int mx = 0;
	for (int i = 1; i <= k; i++) {
		for (int z = 0; z < 4; z++) {
			int nx = x + dx[z] * i, ny = y + dy[z] * i;
			if (1 <= nx && nx <= n && 1 <= ny && ny <= n) {
				if (a[nx][ny] > a[x][y]) {
					mx = max(mx, dfs(nx, ny));
				}
			}
		}
	}
	return dp[x][y]  = a[x][y] + mx;
}
int main()
{
	while (~scanf("%d %d", &n, &k) && (n != -1 && k != -1)) {
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				scanf("%d", &a[i][j]);
			}
		}
		printf("%d\n", dfs(1, 1));
	}
	return 0;
}