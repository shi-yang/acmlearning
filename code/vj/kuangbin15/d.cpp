#include <bits/stdc++.h>
using namespace std;
long long dp[20][2][10];
int dig[20];
long long dfs(int pos, bool limit, int pre, int state)
{
	if (pos == -1)
		return state;
	if (!limit && dp[pos][state][pre] != -1)
		return dp[pos][state][pre];
	int up = limit ? dig[pos] : 9;
	long long ans = 0;
	for (int i = 0; i <= up; i++) {
		if (pre == 4 && i == 9) {
			ans += dfs(pos - 1, limit && i == up, i, 1);
		} else {
			ans += dfs(pos - 1, limit && i == up, i, state);
		}
	}
	if (!limit)
		dp[pos][state][pre] = ans;
	return ans;
}
long long solve(long long n)
{
	int cnt = 0;
	while (n) {
		dig[cnt++] = n % 10;
		n /= 10;
	}
	return dfs(cnt - 1, true, -1, 0);
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--) {
		long long n;
		scanf("%lld", &n);
		memset(dp, -1, sizeof(dp));
		printf("%lld\n", solve(n));
	}
	return 0;
}
