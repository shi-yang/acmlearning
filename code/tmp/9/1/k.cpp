#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
const int N = 100005;
const int inf = 1e9;
struct edge {
	int y, d, c;
	edge() {}
	edge(int y, int d, int c) : y(y), d(d), c(c) {}
};
vector<edge> G[N];
int n, m;
int inq[N];
int dis[N];
int ti[N];
void spfa()
{
	for (int i = 0; i < n; i++)
		inq[i] = 0, dis[i] = inf, ti[i] = inf;
	inq[0] = 1, dis[0] = 0, ti[0] = 0;
	queue<int> que;
	que.push(0);
	while (que.size()) {
		int now = que.front();
		inq[now] = 0;
		que.pop();
		for (int i = 0; i < G[now].size(); i++) {
			edge v = G[now][i];
			if (dis[v.y] >= dis[now] + v.d) {
				dis[v.y] = dis[now] + v.d;
				ti[v.y] = min(v.c, ti[v.y]);
				if (inq[v.y])
					continue;
				inq[v.y] = 1;
				que.push(v.y);
			}
		}
	}
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++)
			G[i].clear();
		for (int i = 0; i < m; i++) {
			int x, y, d, c;
			scanf("%d %d %d %d", &x, &y, &d, &c);
			G[x].push_back(edge(y, d, c));
			G[y].push_back(edge(x, d, c));
		}
		long long mtime = 0, mcost = 0;
		spfa();
		for (int i = 1; i < n; i++) {
			mtime += dis[i];
			mcost += ti[i];
		}
		printf("%lld %lld\n", mtime, mcost);
	}
	return 0;
}
