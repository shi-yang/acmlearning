#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
const int N = 100005;
const int inf = 0x3f3f3f3f;
vector<pair<int, int> > G[N << 2];
int n, m, x;
int d[N << 2];
int l[N << 2];

void dijkstra()
{
	priority_queue<pair<int, int> > que;
	memset(d, inf, sizeof(d));
	d[1] = 0;
	que.push(make_pair(0, 1));
	while (!que.empty()) {
		int now = que.top().second;
		que.pop();
		for (int i = 0; i < G[now].size(); i++) {
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
	int t, kas = 1;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d %d", &n, &m, &x);
		for (int i = 1; i < n; i++) {
			int tt;
			scanf("%d", &tt);
			G[i].push_back(make_pair(tt, x));
			G[tt].push_back(make_pair(i, x));
		}
		for (int i = 0; i < m; i++) {
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			G[a].push_back(make_pair(b, c));
			G[b].push_back(make_pair(a, c));
		}
		dijkstra();
		printf("Case #%d: %d\n", kas++, d[n] == inf ? -1 : d[n]);
	}
	return 0;
}
