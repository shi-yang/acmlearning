#include <bits/stdc++.h>

using namespace std;
const int N = 10;
long long dp[N][N * N][1 << N];
int main()
{
	int n, p;
	scanf("%d %d", &n, &p);
	for (int i = 0; i < 1 << n; i++) {
		if (i & i << 1)
			continue;
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (i & 1 << j) {
				cnt++;
			}
		}
		dp[0][cnt][i] = 1;
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 1 << n; j++) {
			if (j & j << 1)
				continue;
			int cnt = 0;
			for (int c = 0; c < n; c++) {
				if (j & 1 << c)
					cnt++;
			}
			for (int k = 0; k < 1 << n; k++) {
				if (k & k << 1 || k & j || k & j << 1)
					continue;
				int d = 0;
				for (int c = 0; c < n; c++) {
					if (k & 1 << c)
						d++;
				}
				dp[i][j][cnt + d] += dp[i - 1][k][d];
				cout << i << ' ' << dp[i][j][cnt + d] << endl;
			}
		}
	}
	long long ans = 0;
	for (int i = 0; i < 1 << n; i++) {
		ans += dp[n - 1][p][i];
	}
	printf("%lld\n", ans);
	return 0;
}