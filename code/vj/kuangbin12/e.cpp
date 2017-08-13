#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int a[N];
int dp[N];
int main()
{
	int n;
	while (~scanf("%d", &n) && n) {
		for (int i = 0; i < n; i++) {
			scanf("%d", a + i);
		}
		memset(dp, 0, sizeof(dp));
		int ans = 0;
		for (int i = 0; i < n; i++) {
			dp[i] = a[i];
			for (int j = 0; j < i; j++) {
				if (a[i] > a[j]) {
					dp[i] = max(dp[i], dp[j] + a[i]);
				}
			}
			ans = max(dp[i], ans);
		}
		printf("%d\n", ans);
	}
	return 0;
}