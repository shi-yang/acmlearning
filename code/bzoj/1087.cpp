#include <bits/stdc++.h>

using namespace std;
const int N = 10;
long long dp[N][N * N][1 << N];
long long num[1 << N];
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
		num[i] = cnt;
		dp[0][cnt][i] = 1;
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= p; j++) {
			for (int s = 0; s < 1 << n; s++) {
				if (s & s << 1 || j - num[s] < 0)
					continue;
				for (int k = 0; k < 1 << n; k++) {
					if (k & k << 1 || k & s || k & s << 1 || k & s >> 1 || num[k] + num[s] > p)
						continue;
					dp[i][j][s] += dp[i - 1][j - num[s]][k];
				}
			}
		}
	}
	long long ans = 0;
	for (int i = 0; i < 1 << n; i++) {
		if (i & i << 1)
			continue;
		ans += dp[n - 1][p][i];
	}
	printf("%lld\n", ans);
	return 0;
}