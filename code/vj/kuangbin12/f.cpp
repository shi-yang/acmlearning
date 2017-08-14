#include <bits/stdc++.h>
using namespace std;

const int inf = 0x3f3f3f3f;
const int N = 505;
const int M = 10005;
int p[N], w[N], dp[M];
int main()
{
	int tt;
	scanf("%d", &tt);
	while (tt--) {
		memset(dp, inf, sizeof(dp));
		int e, f, n, d;
		scanf("%d%d%d", &e, &f, &n);
		d =  f - e;
		for (int i = 1; i <= n; i++)
			scanf("%d %d", p + i, w + i);
		dp[0] = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = w[i]; j <= d; j++) {
				dp[j] = min(dp[j], dp[j - w[i]] + p[i]);
			}
		}
		if (dp[d] == inf) {
			printf("This is impossible.\n");
		} else {
			printf("The minimum amount of money in the piggy-bank is %d.\n", dp[d]);
		}
	}
	return 0;
}