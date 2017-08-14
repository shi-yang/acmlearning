#include <iostream>
#include <cstdio>
using namespace std;
const int N = 20;
const int md = (int)1e8;
int m, n;
int cur[N];
int dp[N][1 << N];
int main()
{
	scanf("%d %d", &m, &n);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int x;
			scanf("%d", &x);
			if (!x)
				cur[i] |= 1 << j;
		}
	}
	for (int i = 0; i < 1 << n; i++) {
		if (i & (i << 1) || i & cur[0])
			continue;
		dp[0][i] = 1;
	}
	for (int i = 1; i < m; i++) {
		for (int j = 0; j < (1 << n); j++) {
			if ((j & (j << 1)) || j & cur[i])
				continue;
			for (int k = 0; k < (1 << n); k++) {
				if ((k & (k << 1)) || (k & cur[i - 1]) || k & j)
					continue;
				dp[i][j] = (dp[i][j] + dp[i - 1][k]) % md;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < (1 << n); i++) {
		ans = (ans + dp[m - 1][i]) % md;
	}
	printf("%d\n", ans);
	return 0;
}
