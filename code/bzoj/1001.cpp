#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
const int inf = (int) 1e9;
struct edge {
	int to, cap, rev;
	edge(int to, int cap, int rev): to(to), cap(cap), rev(rev) {}
} e[N * N];
//vector<edge> G[N * N];
void add_edge(int from, int to, int cap)
{
	
}
int s, t;
int level[N * N];
int iter[N * N];
bool bfs()
{
	memset(level, -1, sizeof(level));
	queue<int> que;
	level[s] = 0;
	que.push(s);
	while (!que.empty()) {
		int now = que.front();
		que.pop();
		for (int i = 0; i < G[now].size(); i++) {
			edge e = G[now][i];
			if (level[e.to] == -1 && e.cap > 0) {
				level[e.to] = level[now] + 1;
				que.push(e.to);
			}
		}
	}
	return level[t] != -1;
}
int dfs(int u, int t, int f)
{
	if (u == t)
		return f;
	for (int &i = iter[u]; i < G[u].size(); i++) {
		edge &e = G[u][i];
		if (e.cap > 0 && level[e.to] > level[u]) {
			int d = dfs(e.to, t, min(e.cap, f));
			if (d > 0) {
				e.cap -= d;
				G[e.to][e.rev].cap += d;
				return d;
			}
		}
	}
	return 0;
}
int maxflow()
{
	int res = 0;
	while (bfs()) {
        	memset(iter, 0, sizeof(iter));
        	int f;
        	while ((f = dfs(s, t, inf)) > 0) {
            	res += f;
        	}
	}
	return res;
}

int main()
{
	int m, n;
	scanf("%d %d", &n, &m);
	s = 1, t = n * m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m - 1; j++) {
			int x;
			scanf("%d", &x);
			add_edge((i - 1) * m + j, (i - 1) * m + j + 1, x);
			add_edge((i - 1) * m + j + 1, (i - 1) * m + j, x);
		}
	}
	for (int i = 1; i <= n - 1; i++) {
		for (int j = 1; j <= m; j++) {
			int x;
			scanf("%d", &x);
			add_edge((i - 1) * m + j, i * m + j, x);
			add_edge(i * m + j, (i - 1) * m + j, x);
		}
	}
	for (int i = 1; i <= n - 1; i++) {
		for (int j = 1; j <= m - 1; j++) {
			int x;
			scanf("%d", &x);
			add_edge((i - 1) * m + j, i * m + j + 1, x);
			add_edge(i * m + j + 1, (i - 1) * m + j, x);
		}
	}
	printf("%d\n", maxflow());
	return 0;
}