#include <bits/stdc++.h>
using namespace std;
const int N = 10;
double cir[N];
int vis[N];
double rec[N], dis[N];
int n;
double ans;
void dfs(int cur)
{
	if (cur == n + 1) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j < i; j++) {
				if (dis[i] - dis[j] < 2 * sqrt(rec[i] * rec[j])) {
					dis[i] = dis[j] + 2 * sqrt(rec[i] * rec[j]);
				}
			}
		}
		ans = min(ans, dis[n] + rec[n]);
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			vis[i] = 1;
			rec[cur] = cir[i];
			dis[cur] = dis[cur - 1] + 2 * sqrt(rec[cur - 1] * rec[cur]);
			if (cur == 1) {
				dis[1] = cir[i];
			}
			dfs(cur + 1);
			vis[i] = 0;
		}
	}
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%lf", cir + i);
		}
		dis[0] = 0;
		memset(vis, 0, sizeof(vis));
		ans = 0x7fffffff;
		dfs(1);
		printf("%.3lf\n", ans);
	}
	return 0;
}