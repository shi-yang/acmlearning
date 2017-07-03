#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int N = 105;
const int INF = 0x3f3f3f3f;
struct edge {
	int p, l;
}e[N];
vector<pair<int, int> > G[N];
int m, n;
int dis[N];
int dijkstra(int l, int r)
{
	memset(dis, INF, sizeof(dis));
	dis[1] = 0;
	priority_queue<pair<int, int> > que;
	que.push(make_pair(0, 1));
	while (!que.empty()) {
		int now = que.top().second;
		que.pop();
		for (int i = 0; i < (int)G[now].size(); i++) {
			int u = G[now][i].first;
			if (dis[u] > dis[now] + G[now][i].second && e[u].l >= l && e[u].l <= r) {
				dis[u] = dis[now] + G[now][i].second;
				que.push(make_pair(-dis[u], u));
			}
		}
	}
	int res = INF;
	for (int i = 1; i <= n; i++) {
		res = min(res, dis[i] + e[i].p);
	}
	return res;
}

int main()
{
	scanf("%d %d", &m, &n);
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d %d %d", &e[i].p, &e[i].l, &x);
		while (x--) {
			int t, v;
			scanf("%d %d", &t, &v);
			G[i].push_back(make_pair(t, v));
		}
	}
	int ans = 1e9;
	for (int i = 0; i <= m; i++) {
		int l = e[1].l - m + i;
		int r = e[1].l + i;
		ans = min(ans, dijkstra(l, r));
	}
	printf("%d\n", ans);
	return 0;
}
