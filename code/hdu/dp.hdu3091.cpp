#include <bits/stdc++.h>
using namespace std;
const int N = 18;
int G[N][N];
int dp[1 << N][N];
int main()
{
	int n, m;
	while (~scanf("%d%d", &n, &m)) {
		memset(G, 0, sizeof(G));
		for (int i = 0; i < m; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			a--, b--;
			G[a][b] = G[b][a] = 1;
		}
		memset(dp, 0, sizeof(dp));
		dp[1][0] = 1;
		for (int s = 1; s < 1 << n; s++) {
			for (int i = 0; i < n; i++) {
				if (!dp[s][i])
					continue;
				for (int j = 1; j < n; j++) {
					if (s & 1 << j || !G[i][j])
						continue;
					dp[s | 1 << j][j] += dp[s][i];
				}
			}
		}
		long long ans = 0;
		for (int i = 0; i < n; i++) {
			if (G[0][i])
				ans += dp[(1 << n) - 1][i];
		}
		printf("%lld\n", ans);
	}
	return 0;
}