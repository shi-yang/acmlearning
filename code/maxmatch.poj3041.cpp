#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 505;
vector<int> G[maxn];
int match[maxn];
int vis[maxn];
int dfs(int u)
{
	for (int i = 0; i < G[u].size(); i++) {
		if (vis[G[u][i]])
			continue;
		vis[G[u][i]] = 1;
		if (match[G[u][i]] == -1 || dfs(match[G[u][i]])) {
			match[G[u][i]] = u;
			return 1;
		}
	}
	return 0;
}
int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < k; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		G[x].push_back(y);
	}
	memset(match, -1, sizeof(match));
	int res = 0;
	for (int i = 1; i <= n; i++) {
		memset(vis, 0, sizeof(vis));
		res += dfs(i);
	}
	printf("%d\n", res);
	return 0;
}
