#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 15;
const int inf = 0x3f3f3f3f;
int dp[1 << N][N];
int dis[N][N];

int main()
{
	int n;
	while (~scanf("%d", &n), n) {
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				scanf("%d", &dis[i][j]);
			}
		}
		for (int k = 0; k <= n; k++) {
			for (int i = 0; i <= n; i++) {
				for (int j = 0; j <= n; j++) {
					dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
				}
			}
		}
		memset(dp, inf, sizeof(dp));
		dp[(1 << n + 1) - 1][0] = 0;
		for (int i = (1 << n + 1) - 2; i >= 0; i--) {
			for (int j = 0; j <= n; j++) {
				for (int k = 0; k <= n; k++) {
					dp[i][j] = min(dp[i][j], dp[i | 1 << j][k] + dis[j][k]);
				}
			}
		}
		printf("%d\n", dp[0][0]);
	}
	return 0;
}