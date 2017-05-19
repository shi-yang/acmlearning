#include <cstdio>
using namespace std;
const int md = 1e8;
int n, m, top;
int cur[20], dp[20][600], state[600];
inline bool err(int x, int k)
{
	return x & cur[k];
}
int main()
{
	scanf("%d %d", &m, &n);
	top = 0;
	for (int i = 0; i < (1 << n); i++)
		if (!(i & i << 1))
			state[top++] = i;
	for (int i = 1; i <= m; i++) {
		cur[i] = 0;
		for (int j = 1; j <= n; j++) {
			int x; scanf("%d", &x);
			if (!x)
				cur[i] |= 1 << n - j;
		}
	}
	for (int i = 1; i <= top; i++)
		if (!err(state[i], 1))
			dp[1][i] = 1;
	for (int i = 2; i <= m; i++) {
		for (int j = 1; j <= top; j++) {
			if (err(state[j], i))
				continue;
			for (int k = 1; k <= top; k++) {
				if (err(state[k], i - 1) || state[k] & state[j])
					continue;
				dp[i][j] = (dp[i][j] + dp[i - 1][k]) % md;
			}
		}
	}
	int res = 0;
	for (int i = 1; i <= top; i++)
		res = (res + dp[m][i]) % md;
	printf("%d\n", res);
	return 0;
}
