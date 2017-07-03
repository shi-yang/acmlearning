#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
const int N = 1e6 + 5;
vector<pair<int, int> > G[N];
int dis[N];
struct edge {
	int u, v, c;
} e[N];
void spfa(int s)
{
	for (int i = 0; i < N; i++) {
		dis[i] = 1e9;
	}
	dis[s] = 0;
	priority_queue<pair<int, int> > que;
	que.push(make_pair(s, 0));
	while (que.size()) {
		int now = que.top().first;
		que.pop();
		for (int i = 0; i < G[now].size(); i++) {
			int v = G[now][i].first;
			if (dis[v] > dis[now] + G[now][i].second) {
				dis[v] = dis[now] + G[now][i].second;
				que.push(make_pair(v, -dis[v]));
			}
		}
	}
}
void init(int x)
{
	for (int i = 1; i <= x; i++)
		G[i].clear();
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--) {
		int p, q;
		scanf("%d %d", &p, &q);
		init(p);
		for (int i = 0; i < q; i++) {
			scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].c);
			G[e[i].u].push_back(make_pair(e[i].v, e[i].c));
		}
		spfa(1);
		long long ans = 0;
		for (int i = 1; i <= p; i++) {
			ans += dis[i];
		}
		init(p);
		for (int i = 0; i < q; i++) {
			G[e[i].v].push_back(make_pair(e[i].u, e[i].c));
		}
		spfa(1);
		for (int i = 1; i <= p; i++) {
			ans += dis[i];
		}
		printf("%lld\n", ans);
	}
	return 0;
}
