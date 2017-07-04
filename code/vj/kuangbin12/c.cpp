#include <bits/stdc++.h>
using namespace std;
const int N = 35;
struct edge {
	int x, y, z;
	bool operator < (const edge &a) const {
		if (x == a.x) {
			if (y == a.y)
				return z < a.z;
			return y < a.y;
		}
		return x < a.x;
	}
} e[N * 6];
int dp[N * 6];
int main()
{
	int n, cas = 1;
	while (~scanf("%d", &n) && n) {
		memset(dp, 0, sizeof(dp));
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			int x, y, z;
			scanf("%d %d %d", &x, &y, &z);
			e[cnt].x = x, e[cnt].y = y, e[cnt].z = z;
			cnt++;
			e[cnt].x = x, e[cnt].y = z, e[cnt].z = y;
			cnt++;
			e[cnt].x = y, e[cnt].y = x, e[cnt].z = z;
			cnt++;
			e[cnt].x = y, e[cnt].y = z, e[cnt].z = x;
			cnt++;
			e[cnt].x = z, e[cnt].y = y, e[cnt].z = x;
			cnt++;
			e[cnt].x = z, e[cnt].y = x, e[cnt].z = y;
			cnt++;
		}
		sort(e, e + cnt);
		dp[0] = e[0].z;
		for (int i = 1; i < cnt; i++) {
			int mx = 0;
			for (int j = 0; j < i; j++) {
				if (e[i].x > e[j].x && e[i].y > e[j].y || e[i].x > e[j].y && e[i].y > e[j].x)
					mx = max(mx, dp[j]);
			}
			dp[i] = mx + e[i].z;
		}
		int ans = 0;
		for (int i = 0; i < cnt; i++)
			ans = max(ans, dp[i]);
		printf("Case %d: maximum height = %d\n", cas++, ans);
	}
	return 0;
}
