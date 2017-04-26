#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int a[maxn];
int val[maxn];
int count[maxn];
int num[maxn];
int left[maxn];
int right[maxn];
int dp[maxn][32];
int n, q;
void rmq_init()
{
	for (int i = 0; i < n; i++)
		dp[i][0] = b[i];
	for (int j = 1; (1 << j) <= n; j++)
		for (int i = 0; i + (1 << j) - 1 < n; i++)
			dp[i][j] = min(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
}
int rmq(int l, int r)
{
	int k = 0;
	while ((1 << (k + 1) <= r - l + 1))	k++;
	return min(dp[l][k], dp[r - (1 << k) + 1][k]);
}
int main()
{
	while (~scanf("%d %d", &n, &q) && n) {
		for (int i = 0; i < n; i++) {
			scanf("%d", a + i);
		}
		rmq_init();
		while (q--) {
			int x, y;
			scanf("%d %d", &x, &y);
			printf("%d\n", rmq(x, y));
		}
	}
	return 0;
}
