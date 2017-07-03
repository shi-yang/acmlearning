#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
const int inf = 0x3f3f3f3f;
int n, m;
int a, b, c;
int s, t;
vector<pair<int, int> > G[N];
int d[N];

void dijkstra()
{
	memset(d, inf, sizeof(d));
	d[s] = 0;
	priority_queue<pair<int, int> > que;
	que.push(make_pair(0, s));
	while (!que.empty()) {
		int now = que.top().second;
		for (int i = 0; i < (int) G[now].size(); i++) {
			int v = G[now][i].first;
			if (d[v] > d[now] + G[now][i].second) {
				d[v] = d[now] + G[now][i].second;
				que.push(make_pair(-d[v], v));
			}
		}
	}
}
int main()
{
	int tt;
	scanf("%d", &tt);
	while (tt--) {
		for (int i = 0; i < N; i++)
			G[i].clear();
		scanf("%d %d", &n, &m);
		for (int i = 0; i < m; i++) {
			scanf("%d %d %d", &a, &b, &c);
			if (a == b)	continue;
			G[a].push_back(make_pair(b, c));
		}
		scanf("%d %d", &s, &t);
		dijkstra();
		printf("%d\n", d[t]);
	}
	return 0;
}