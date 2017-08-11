#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int N = 20005;
int size[N], fa[N];
vector<int> G[N];
void dfs(int u)
{
	size[u] = 1;
	for (int i = 0; i < (int) G[u].size(); i++) {
		int v = G[u][i];
		if (v == fa[u])
			continue;
		fa[v] = u;
		dfs(v);
		size[u] += size[v];
	}	
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		memset(fa, 0, sizeof(fa));
		for (int i = 1; i <= n; i++)
			G[i].clear();
		for (int i = 1; i < n; i++) {
			int u, v;
			scanf("%d %d", &u, &v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dfs(1);
		int ans = (int) 1e9;
		int u;
		for (int i = 1; i <= n; i++) {
			int mx = n - size[i];
			for (int j = 0; j < (int) G[i].size(); j++) {
				if (fa[i] != G[i][j]) {
					mx = max(mx, size[G[i][j]]);
				}
			}
			if (mx < ans) {
				ans = mx;
				u = i;
			}
		}
		printf("%d %d\n", u, ans);
	}
	return 0;
}