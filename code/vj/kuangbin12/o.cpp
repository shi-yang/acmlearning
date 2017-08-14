#include <iostream>
#include <cstdio>
using namespace std;
const int N = 2005;
int a[N], dp[N][N];
int n;
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
	}
	for (int i = n; i >= 1; i--) {
		for (int j = i; j <= n; j++) {
			dp[i][j] = max(dp[i + 1][j] + a[i] * (n - j + i), dp[i][j - 1] + a[j] * (n - j + i));
		}
	}
	printf("%d\n", dp[1][n]);
	return 0;
}