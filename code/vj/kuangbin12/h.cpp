#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 2005;
int a[N], b[N];
int dp[N];
int main()
{
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", a + i);
		}
		for (int i = 2; i <= n; i++) {
			scanf("%d", b + i);
		}
		memset(dp, inf, sizeof(dp));
		dp[0] = 0;
		dp[1] = a[1];
		for (int i = 2; i <= n; i++) {
			dp[i] = min(dp[i - 1] + a[i], dp[i - 2] + b[i]);
		}
		int mi = dp[n] / 60;
		int h = mi / 60 + 8;
		int s = dp[n] % 60;
		mi %= 60;
		if (h > 12) {
			printf("%02d:%02d:%d pm\n", h - 12, mi, s);
		} else {
			printf("%02d:%02d:%02d am\n", h, mi, s);
		}
	}
	return 0;
}