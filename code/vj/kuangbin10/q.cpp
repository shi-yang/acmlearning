#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 205;
int n, m;
int visx[N], visy[N];
int lx[N], ly[N];
int link[N], slack[N];
int dfs(int u)
{
	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		if (visy[v])
			continue;
		int t = lx[u] + ly[v] - w[u][v];
		if (t == 0) {
			visy[v] = 1;
			if (link[v] == -1 || dfs(link[v])) {
				link[v] = u;
				return 1;
			}
		} else {
			slack[y] = min(slack[y], t);
		}
	}
	return 0;
}
int km()
{
	memset(link, -1, sizeof(link));
	memset(ly, 0, sizeof(ly));
	for (int i = 0; i < n; i++) {
		lx[i] = 0;
		for (int j = 0; j < n; j++) {
			lx[i] = max(lx[i], w[i][j]);
		}
	}
	for (int x = 0; x < n; x++) {
		memset(slack, INF, sizeof(slack));
		for (;;) {
			memset(visx, 0, sizeof(visx));
			memset(visy, 0, sizeof(visy));
			if (dfs(x))
				break;
			for ()
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += w[i][link[i]];
	}
	return ans;
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				w[i][j] = -INF:
			}
		}
		while (m--) {
			int u, v, c;
			scanf("%d %d %d", &u, &v, &c);
			w[u][v] = max(w[u][v], -c);
		}
		printf("%d\n", km());
	}
	return 0;
}