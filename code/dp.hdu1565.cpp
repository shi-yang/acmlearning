#include <bits/stdc++.h>
using namespace std;
const int maxn = 21;
int n;
int m[maxn][maxn];
int dp[maxn][17777];
int state[17777];
int main()
{
	while (~scanf("%d", &n)) {
		int top = 0;
		for (int i = 0; i < 1 << n; i++) {
			if (!(i & i << 1))
				state[top++] = i;
		}
		if (!n) {
			printf("0\n");
			continue;
		}
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				scanf("%d", &m[i][j]);
			}
		}
		for (int i = 0; i < top; i++) {
			for (int k = 1; k <= n; k++)
				if (state[i] & 1 << k - 1)
					dp[1][i] += m[1][k];
		}
		for (int i = 2; i <= n; i++) {
			for (int j = 0; j < top; j++) {
				int tmp = 0;
				for (int v = 1; v <= n; v++)
					if (state[j] & 1 << v - 1)
						tmp += m[i][v];
				if (!tmp) {
					dp[i][j] = dp[i - 1][j];
					continue;
				}
				for (int k = 0; k < top; k++) {
					if (state[j] & state[k])
						continue;
					dp[i][j] = max(dp[i][j], dp[i - 1][k] + tmp);
				}
			}
		}
		int res = 0;
		for (int i = 0; i < top; i++) {
			res = max(res, dp[n][i]);
		}
		printf("%d\n", res);
	}
	return 0;
}
