#include <iostream>
#include <cstdio>

double dp[1005][1005];
int main()
{
	int n, s;
	scanf("%d %d", &n, &s);
	dp[n][s] = 0.0;
	double ns = 1.0 * n * s;
	for (int i = n; i >= 0; i--) {
		for (int j = s; j >= 0; j--) {
			if (i == n && j == s)
				continue;
			dp[i][j] = (ns + 
						(n - i) * j * dp[i + 1][j] + 
						i * (s - j) * dp[i][j + 1] + 
						(n - i) * (s - j)  * dp[i + 1][j + 1]) / (ns - i * j);
		}
	}
	printf("%.4lf\n", dp[0][0]);
	return 0;
}