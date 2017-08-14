#include <bits/stdc++.h>
using namespace std;
const int N = 20;
int dp[N][20000];
int a[N][N];
int sta[20000];
int main()
{
	int n;
	while (~scanf("%d", &n)) {
		if (!n) {
			printf("0\n");
			continue;
		}
		int top = 0;
		for (int i = 0; i < 1 << n; i++) {
			if (i & i << 1)
				continue;
			sta[top++] = i;
		}
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &a[i][j]);
			}
		}
		for (int i = 0; i < top; i++) {
			for (int j = 0; j < n; j++) {
				if (sta[i] & 1 << j) {
					dp[0][i] += a[0][j];
				}
			}
		}
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < top; j++) {
				int d = 0;
				for (int k = 0; k < top; k++) {
					if (sta[j] & sta[k])
						continue;
					d = max(d, dp[i - 1][k]);
				}
				for (int k = 0; k < n; k++) {
					if (sta[j] & 1 << k) {
						dp[i][j] += a[i][k];
					}
				}
				dp[i][j] += d;
			}
		}
		int ans = 0;
		for (int i = 0; i < 1 << n; i++) {
			ans = max(ans, dp[n - 1][i]);
		}
		printf("%d\n", ans);
	}
	return 0;
}