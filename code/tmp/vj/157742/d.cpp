#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 1005;
const int inf = 1e9;
vector<pair<int, int> > G[maxn];
int n, m, x;
int d[maxn][maxn];
void dijkstra(int s)
{
	priority_queue<pair<int, int> > que;
	for (int i = 1; i <= n; i++)
		d[s][i] = inf;
	d[s][s] = 0;
	que.push(make_pair(-d[s][s], s));
	while (!que.empty()) {
		int now = que.top().second;
		que.pop();
		for (int i = 0; i < G[now].size(); i++) {
			int v = G[now][i].first;
			if (d[s][v] > d[s][now] + G[now][i].second) {
				d[s][v] = d[s][now] + G[now][i].second;
				que.push(make_pair(-d[s][v], v));
			}
		}
	}
}
int main()
{
	scanf("%d %d %d", &n, &m, &x);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		G[a].push_back(make_pair(b, c));
	}
	for (int i = 1; i <= n; i++) {
		dijkstra(i);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, d[i][x] + d[x][i]);
	}
	printf("%d\n", ans);
	return 0;
}
