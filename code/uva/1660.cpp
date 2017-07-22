#include <bits/stdc++.h>
using namespace std;
const int N = 55;
const int inf = 0x3f3f3f3f;
int n, m;
struct edge {
	int from, to, cap, rev;
};
vector<edge> G[N << 2];
vector<edge> G_B[N << 2];
int level[N << 2], iter[N << 2];
void add_edge(int from, int to, int cap)
{
	G_B[from].push_back((edge){from, to, cap, G_B[to].size()});
	G_B[to].push_back((edge){to, from, 0, G_B[from].size() - 1});
}
bool bfs(int s, int t)
{
	queue<int> que;
	que.push(s);
	memset(level, -1, sizeof(level));
	level[s] = 0;
	while (!que.empty()) {
		int now = que.front();
		que.pop();
		for (auto e : G[now]) {
			if (e.cap > 0 && level[e.to] == -1) {
				level[e.to] = level[now] + 1;
				que.push(e.to);
			}
		}
	}
	return level[t] != -1;
}
int dfs(int u, int v, int f)
{
	if (u == v)
		return f;
	for (int &i = iter[u]; i < G[u].size(); i++) {
		edge &e = G[u][i];
		if (e.cap > 0 && level[u] < level[e.to]) {
			int d = min(f, dfs(e.to, v, e.cap));
			if (d > 0) {
				e.cap -= d;
				G[e.to][e.rev].cap += d;
				return d;
			}
		}
	}
	return 0;
}
int maxflow(int s, int t)
{
	int flow = 0, f;
	while (bfs(s, t)) {
		memset(iter, 0, sizeof(iter));
		while ((f = dfs(s, t, inf)) > 0)
			flow += f;
	}
	return flow;
}
int main()
{
	while (~scanf("%d %d", &n, &m)) {
		for (int i = 0; i < n << 2; i++)
			G[i].clear(), G_B[i].clear();
		for (int i = 0; i < n; i++) {
			add_edge(i, i + n, 1);
		}
		for (int i = 0; i < m; i++) {
			int u, v;
          	scanf(" (%d,%d)",&u,&v);
          	add_edge(u + n, v, inf);
          	add_edge(v + n, u, inf);
		}
		int ans = n;
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < n << 2; j++)
				G[j] = G_B[j];
			ans = min(ans, maxflow(n, i));
		}
		printf("%d\n", ans);
	}
	return 0;
}