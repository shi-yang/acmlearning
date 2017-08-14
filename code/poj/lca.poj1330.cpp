#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int N = 10005;
int n;
int vis[N], f[N];
vector<int> G[N];
int s, t, ans;
int root(int x)
{
	return x == f[x] ? x : f[x] = root(f[x]);
}
void dfs(int u)
{
	vis[u] = 1;
	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		if (vis[v])
			continue;
		dfs(v);
		f[v] = u;
	}
	if (u == s && vis[t]) {
		ans = root(t);
		return;
	} else if (u == t && vis[s]) {
		ans = root(s);
		return;
	}
}
int main()
{
	int tt;
	scanf("%d", &tt);
	while (tt--) {
		scanf("%d", &n);
		memset(vis, 0, sizeof(vis));
		for (int i = 1; i <= n; i++) {
			f[i] = i;
			G[i].clear();
		}
		for (int i = 1; i < n; i++) {
			int u, v;
			scanf("%d %d", &u, &v);
			G[u].push_back(v);
			G[v].push_back(u);
			f[v] = u;
		}
		int r = root(1);
		for (int i = 1; i <= n; i++)
			f[i] = i;
		scanf("%d %d", &s, &t);
		dfs(r);
		printf("%d\n", ans);
	}
	return 0;
}