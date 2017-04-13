#include <iostream>
#include <cstdio>

using namespace std;
const int maxn = 1005;
int val[maxn];
int vol[maxn];
int dp[maxn][maxn];
int main()
{
	int t;
	scanf("%d" ,&t);
	while (t--) {
		int n, v;
		scanf("%d %d", &n, &v);
		for (int i = 0; i < n; i++) {
			scanf("%d", &val[i]);
		}
		for (int i = 0; i < n; i++) {
			scanf("%d", &vol[i]);
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= v; j++) {
				if (j - vol[i] >= 0) {
					dp[i + 1][j] = max(dp[i][j], dp[i][j - vol[i]] + val[i]);
				} else {
					dp[i + 1][j] = dp[i][j];
				}
			}
		}
		printf("%d\n", dp[n][v]);
	}
	return 0;
}
