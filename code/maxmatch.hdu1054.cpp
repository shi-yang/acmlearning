#include <bits/stdc++.h>
using namespace std;
const int N = 1505;
vector<int> G[N];
int match[N], used[N];
int n;
int dfs(int u)
{
	for (int v : G[u]) {
		if (used[v])
			continue;
		used[v] = 1;
		if (match[v] == -1 || dfs(match[v])) {
			match[v] = u;
			return 1;
		}
	}
	return 0;
}
int main()
{
	while (~scanf("%d", &n)) {
		for (int i = 0; i < n; i++)
			G[i].clear();
		for (int i = 0; i < n; i++) {
			int u, m, x;
			scanf("%d:(%d)", &u, &m);
			for (int i = 0; i < m; i++) {
				scanf("%d", &x);
				G[u].push_back(x);
				G[x].push_back(u);
			}
		}
		memset(match, -1, sizeof(match));
		int res = 0;
		for (int i = 0; i < n; i++) {
			memset(used, 0, sizeof(used));
			res += dfs(i);
		}
		printf("%d\n", res / 2);
	}
	return 0;
}
