#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
const int inf = 1e9;
const int maxn = 1005;
vector<pair<int, int> > G[maxn];
int d[maxn];
int m, n;
int inq[maxn];
int spfa(int s)
{
	memset(inq, 0, sizeof(inq));
	memset(d, 0, sizeof(d));
	d[s] = inf;
	inq[s] = 1;
	queue<int> que;
	que.push(s);
	while (que.size()) {
		int now = que.front();
		que.pop();
		inq[now] = 1;
		for (int i = 0; i < G[now].size(); i++) {
			int v = G[now][i].first;
			if (d[v] < min(G[now][i].second, d[now])) {
				d[v] = min(G[now][i].second, d[now]);
				if (inq[v])
					continue;
				inq[v] = 1;
				que.push(v);
			}
		}
	}
}
int main()
{
	int t;
	scanf("%d", &t);
	for (int tt = 1; tt <= t; tt++) {
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i++)
			G[i].clear();
		for (int i = 0; i < m; i++) {
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			G[a].push_back(make_pair(b, c));
			G[b].push_back(make_pair(a, c));
		}
		spfa(1);
		printf("Scenario #%d:\n", tt);
		printf("%d\n\n", d[n]);
	}
	return 0;
}
