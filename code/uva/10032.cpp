#include <bits/stdc++.h>
using namespace std;
int a[105], dp[45005], cnt[45005][55];
int main()
{
	int t, n;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		int sum = 0, mid;
		for (int i = 0; i < n; i++) {
			scanf("%d", a + i);
			sum += a[i];
		}
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		for (int i = 0; i < n; i++) {
			for (int j = sum; j >= a[i]; j--) {
				if (dp[j - a[i]]) {
					dp[a[i]] = 1;
					for (int k = 0; k <= 50; k++) {
						if (cnt[j - a[i]][k])
							cnt[a[i]][k + 1] = 1;
					}
				}
			}
		}
		for (int i = 0; i <= 25005; i++) {
			if ()
		}
		cout << dp[290] << endl;
		if (t) puts("");
	}
	return 0;
}