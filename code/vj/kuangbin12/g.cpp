#include <cstdio>
#include <cstring>
using namespace std;
const int N = (int)1e5 + 5;
int dp[N][15];
int max(int a, int b, int c)
{
	if (a >= b && a >= c)
		return a;
	else if (b >= a && b >= c)
		return b;
	else
		return c;
}
int main()
{
	int n;
	while (~scanf("%d", &n) && n) {
		int time = 0;
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < n; i++) {
			int t, x;
			scanf("%d %d", &x, &t);
			dp[t][x]++;
			time = max(time, t, 0);
		}
		for (int i = time; i >= 0; i--) {
			for (int j = 0; j <= 10; j++) {
				if (j == 0) {
					dp[i][j] += max(dp[i + 1][j], dp[i + 1][j + 1], 0);
				} else if (j == 10) {
					dp[i][j] += max(dp[i + 1][j - 1], dp[i + 1][j], 0);
				} else {
					dp[i][j] += max(dp[i + 1][j - 1], dp[i + 1][j], dp[i + 1][j + 1]);
				}
			}
		}
		printf("%d\n", dp[0][5]);
	}
	return 0;
}
