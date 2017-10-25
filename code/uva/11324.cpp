#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
vector<int> G[N];
int dfn[N], low[N], sccno[N];
stack<int> s;
int dfs_clock, scc_cnt;
vector<int> mp[N];
int dp[N], val[N];
int dfs(int u)
{
	low[u] = dfn[u] = ++dfs_clock;
	s.push(u);
	for (auto v: G[u]) {
		if (!dfn[v]) {
			dfs(v);
			low[u] = min(low[u], low[v]);
		} else if (!sccno[v]) {
			low[u] = min(low[u], dfn[v]);
		}
	}
	if (low[u] == dfn[u]) {
		scc_cnt++;
		for (;;) {
			int x = s.top();
			s.pop();
			sccno[x] = scc_cnt;
			if (x == u)
				break;
		}
	}
}
int fdp(int u)
{
	if (dp[u] > 0)
		return dp[u];
	for (auto v : mp[u]) {
		dp[u] = max(dp[u], fdp(v));
	}
	return dp[u] = dp[u] + val[u];
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, m;
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i++) {
			G[i].clear();
			mp[i].clear();
		}
		for (int i = 0; i < m; i++) {
			int u, v;
			scanf("%d %d", &u, &v);
			G[u].push_back(v);
		}
		memset(dfn, 0, sizeof(dfn));
		memset(sccno, 0, sizeof(sccno));
		dfs_clock = 0;
		for (int i = 1; i <= n; i++) {
			if (!dfn[i]) {
				dfs(i);
			}
		}
		memset(val, 0, sizeof(val));
		for (int i = 1; i <= n; i++) {
			val[sccno[i]]++;
		}
		for (int i = 1; i <= n; i++) {
			for (auto v: G[i]) {
				if (sccno[i] != sccno[v]) {
					mp[sccno[i]].push_back(sccno[v]);
				}
			}
		}
		int ans = 0;
		for (int i = 1; i <= scc_cnt; i++) {
			memset(dp, 0, sizeof(dp));
			ans = max(ans, fdp(i));
		}
		printf("%d\n", ans);
	}
	return 0;
}