#include <bits/stdc++.h>
using namespace std;

int dig[10];
int dp[10][2];
int dfs(int pos, bool limit, int state, int pre)
{
	if (pos == -1)
		return 1;
	if (!limit && dp[pos][state] != -1)
		return dp[pos][state];
	int up = limit ? dig[pos] : 9;
	int ans = 0;
	for (int i = 0; i <= up; i++) {
		if (i == 4 || i == 2 && pre == 6) {
			continue;
		}
		ans += dfs(pos - 1, limit && i == dig[pos], i == 6, i);
	}
	if (!limit)
		dp[pos][state] = ans;
	return ans;
}
int solve(int x)
{
	int cnt = 0;
	while (x) {
		dig[cnt++] = x % 10;
		x /= 10;
	}
	return dfs(cnt - 1, true, 0, -1);
}
int main()
{
	int l, r;
	while (~scanf("%d %d", &l, &r) && (l + r)) {
		memset(dp, -1, sizeof(dp));
		printf("%d\n", solve(r) - solve(l - 1));
	}
	return 0;
}
