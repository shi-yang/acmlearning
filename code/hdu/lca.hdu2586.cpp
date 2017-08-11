#include <bits/stdc++.h>
using namespace std;
const int N = 40005;
vector<pair<int, int> > G[N];
vector<pair<int, int> > que[N];
int ans[205];
int vis[N];
int dis[N], f[N];
int n, m;
int root(int x)
{
	return x == f[x] ? x : f[x] = root(f[x]);
}
void dfs(int x)
{
	vis[x] = 1;
	for (auto v : G[x]) {
		if (vis[v.first])
			continue;
		dis[v.first] = dis[x] + v.second;
		dfs(v.first);
		f[v.first] = x;
	}
	for (auto v : que[x]) {
		if (vis[v.first]) {
			ans[v.second] = dis[v.first] + dis[x] - 2 * dis[root(v.first)];
		}
	}
}
void init()
{
	for (int i = 1; i <= n; i++) {
		vis[i] = 0;
		f[i] = i;
		G[i].clear();
		que[i].clear();
		dis[i] = 0;
	}
}
int main()
{
	int tt;
	scanf("%d", &tt);
	while (tt--) {
		scanf("%d %d", &n, &m);
		init();
		for (int i = 1; i < n; i++) {
			int u, v, c;
			scanf("%d %d %d", &u, &v, &c);
			G[u].push_back(make_pair(v, c));
			G[v].push_back(make_pair(u, c));
		}
		for (int i = 0; i < m; i++) {
			int u, v;
			scanf("%d %d", &u, &v);
			que[u].push_back(make_pair(v, i));
			que[v].push_back(make_pair(u, i));
		}
		dfs(1);
		for (int i = 0; i < m; i++) {
			printf("%d\n", ans[i]);
		}
	}
	return 0;
}