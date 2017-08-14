#include <bits/stdc++.h>
using namespace std;
const int N = 505;
vector<int> G[N];
int match[N + N], vis[N + N];
bool dfs(int u)
{
	for (int i = 0; i < (int) G[u].size(); i++) {
		int v = G[u][i];
		if (!vis[v]) {
			vis[v]++;
			if (match[v] == -1 || dfs(match[v])) {
				match[v] = u;
				return true;
			}
		}
	}
	return false;
}
int main()
{
	int n, k, m;
	while (~scanf("%d", &k), k) {
		scanf("%d %d", &m, &n);
		memset(match, -1, sizeof(match));
		for (int i = 0; i < N; i++)
			G[i].clear();
		for (int i = 0; i < k; i++) {
			int u, v;
			scanf("%d %d", &u, &v);
			G[u].push_back(v + m);
		}
		int ans = 0;
		for (int i = 1; i <= m; i++) {
			if (match[i] == -1) {
				memset(vis, 0, sizeof(vis));
				ans += dfs(i);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}