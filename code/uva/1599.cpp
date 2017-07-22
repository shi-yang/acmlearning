#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, m;
struct edge {
	int v, c;
};
vector<edge> G[N];
int color[N];
int cnt[N];
int vis[N];
int main()
{
	while (~scanf("%d %d", &n, &m)) {
		for (int i = 1; i <= n; i++)
			G[i].clear();
		for (int i = 0; i < m; i++) {
			int u, v, c;
			scanf("%d %d %d", &u, &v, &c);
			G[u].emplace_back((edge){v, c});
			G[v].emplace_back((edge){u, c});
		}
		queue<int> que;
		que.push(n);
		memset(cnt, -1, sizeof(cnt));
		cnt[n] = 0;
		while (!que.empty()) {
			int now = que.front();
			que.pop();
			for (auto e : G[now]) {
				if (cnt[e.v] == -1) {
					cnt[e.v] = cnt[now] + 1;
					que.push(e.v);
				}
			}
			if (cnt[1] != -1)
				break;
		}
		while (!que.empty())
			que.pop();
		memset(color, 0, sizeof(color));
		memset(vis, 0, sizeof(vis));
		vis[1] = 1;
		que.push(1);
		while (!que.empty()) {
			int now = que.front();
			que.pop();
			int mi = (int) 1e9;
			for (auto e: G[now]) {
				if (cnt[e.v] == cnt[now] - 1) {
					mi = min(mi, e.c);
				}
			}
			int t = cnt[1] - cnt[now];
			if (color[t] == 0)
				color[t] = mi;
			else
				color[t] = min(color[t], mi);
			if (now == n)
				break;
			for (auto e: G[now]) {
				if (cnt[e.v] == cnt[now] - 1 && e.c == mi && !vis[e.v]) {
					vis[e.v]++;
					que.push(e.v);
				}
			}
		}
		printf("%d\n", cnt[1]);
		for (int i = 0; i < cnt[1]; i++) {
			if (i)
				putchar(' ');
			printf("%d", color[i]);
		}
		putchar('\n');
	}
	return 0;
}