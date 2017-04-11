#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 1005;
const int inf = 1e9;
int t, n;
vector<pair<int, int> > G[maxn];
int inq[maxn];
int d[maxn];
void spfa()
{
	queue<int> que;
	for (int i = 0; i <= n; i++)
		d[i] = inf;
	que.push(1);
	d[1] = 0;
	inq[1] = 1;
	while (que.size()) {
		int now = que.front();
		que.pop();
		inq[now] = 0;
		for (int i = 0; i < G[now].size(); i++) {
			int v = G[now][i].first;
			if (d[v] > d[now] + G[now][i].second) {
				d[v] = d[now] + G[now][i].second;
				if (inq[v])
					continue;
				inq[v] = 1;
				que.push(v);
			}
		}
	}
	printf("%d\n", d[n]);
}
int main()
{
	scanf("%d %d", &t, &n);
	for (int i = 0; i < t; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		G[a].push_back(make_pair(b, c));
		G[b].push_back(make_pair(a, c));
	}
	spfa();
	return 0;
}
