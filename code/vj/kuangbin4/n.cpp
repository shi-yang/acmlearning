#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

const int N = 105;
const int inf = 0x3f3f3f3f;
int n, a, b;
vector<pair<int, int> > G[N];
int dis[N];

void dijkstra()
{
	memset(dis, inf, sizeof(dis));
	priority_queue<pair<int, int> > que;
	que.push(make_pair(0, a));
	dis[a] = 0;
	while (que.size()) {
		int now = que.top().second;
		que.pop();
		for (int i = 0; i < G[now].size(); i++) {
			int v = G[now][i].first;
			if (dis[v] > dis[now] + G[now][i].second) {
				dis[v] = dis[now] + G[now][i].second;
				que.push(make_pair(-dis[v], v));
			}
		}
	}
}
int main()
{
	cin >> n >> a >> b;
	for (int i = 1; i <= n; i++) {
		int x, y, d;
		cin >> x;
		for (int j = 0; j < x; j++) {
			cin >> y;
			d = j ? 1 : 0;
			G[i].push_back(make_pair(y, d));
		}
	}
	dijkstra();
	if (dis[b] == inf) {
		printf("-1\n");
	} else {
		printf("%d\n", dis[b]);
	}
	return 0;
}
