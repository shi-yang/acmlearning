#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <map>
using namespace std;
const int N = 805;
const int inf = (int) 1e9;
int n, m, k;
int s, t;
map<string, int> ss;
int path[N];
int a[N];
struct edge {
	int from, to, flow, cap;
	edge(int u, int v, int c, int f) : from(u), to(v), cap(c), flow(f) {}
};
vector<edge> E;
vector<int> G[N];
void add_edge(int from, int to, int cap)
{
	E.push_back(edge(from, to, cap, 0));
	E.push_back(edge(to, from, 0, 0));
	int q = E.size();
	G[from].push_back(q - 2);
	G[to].push_back(q - 1);
}
int maxflow()
{
	int flow = 0;
	for (;;) {
		memset(a, 0, sizeof(a));
		queue<int> que;
		que.push(s);
		a[s] = inf;
		while (!que.empty()) {
			int now = que.front(); que.pop();
			for (int i = 0; i < G[now].size(); i++) {
				edge &e = E[G[now][i]];
				if (!a[e.to] && e.cap > e.flow) {
					path[e.to] = G[now][i];
					a[e.to] = min(a[now], e.cap - e.flow);
					que.push(e.to);
				}
			}
			if (a[t]) break;
		}
		if (!a[t])
			break;
		for (int i = t; i != s; i = E[path[i]].from) {
			E[path[i]].flow += a[t];
			E[path[i] ^ 1].flow -= a[t];
		}
		flow += a[t];
	}
	return flow;
}
int main()
{
	while (~scanf("%d", &n)) {
		ss.clear();
		for (int i = 0; i < N; i++) {
			G[i].clear();
		}
		E.clear();
		s = 0, t = N - 1;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			string str;
			cin >> str;
			ss[str] = ++cnt;
			add_edge(cnt, t, 1);
		}
		scanf("%d", &m);
		for (int i = 0; i < m; i++) {
			string x, y;
			cin >> x >> y;
			ss[x] = ++cnt;
			if (!ss[y]) {
				ss[y] = ++cnt;
			}
			add_edge(ss[x], ss[y], 1);
			add_edge(s, ss[x], 1);
		}
		scanf("%d", &k);
		for (int i = 0; i < k; i++) {
			string x, y;
			cin >> x >> y;
			if (!ss[x]) {
				ss[x] = ++cnt;
			}
			if (!ss[y]) {
				ss[y] = ++cnt;
			}
			add_edge(ss[x], ss[y], inf);
		}
		printf("%d\n", m - maxflow());
	}
	return 0;
}