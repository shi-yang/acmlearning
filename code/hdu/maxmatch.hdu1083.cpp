#include <bits/stdc++.h>

using namespace std;
const int N = 305;
int p, n;
int match[N], vis[N];
vector<int> G[N];
bool dfs(int u)
{
	for (auto v : G[u]) {
		if (vis[v])
			continue;
		vis[v]++;
		if (match[v] == -1 || dfs(match[v])) {
			match[v] = u;
			return true;
		}
	}
	return false;
}
int main()
{
	int tt;
	scanf("%d", &tt);
	while (tt--) {
		scanf("%d %d", &p, &n);
		for (int i = 0; i < p; i++) {
			G[i].clear();
			int c, v;
			scanf("%d", &c);
			while (c--) {
				scanf("%d", &v);
				G[i].push_back(v);
			}
		}
		int sum = 0;
		memset(match, -1, sizeof(match));
		for (int i = 0; i < p; i++) {
			memset(vis, 0, sizeof(vis));
			if (dfs(i))
				sum++;
		}
		if (sum == p) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
}