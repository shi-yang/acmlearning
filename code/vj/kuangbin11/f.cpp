#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 205;
char str[N];
int a[N << 3];
int path[N << 3];
struct edge {
	int from, to, cap, flow;
};
vector<edge> E;
vector<int> G[N << 3];
void add_edge(int from, int to, int flow)
{
	E.push_back((edge){from, to, flow, 0});
	E.push_back((edge){to, from, 0, 0});
	int q = E.size();
	G[from].push_back(q - 2);
	G[to].push_back(q - 1);
}
int level[N << 3];
int cur[N << 3];
bool bfs(int s, int t)
{
	memset(level, -1, sizeof(level));
	level[s] = 0;
	queue<int> que;
	que.push(s);
	while (!que.empty()) {
		int now = que.front();
		que.pop();
		for (int i = 0; i < G[now].size(); i++) {
			edge e = E[G[now][i]];
			if (e.cap - e.flow > 0 && level[e.to] == -1) {
				level[e.to] = level[now] + 1;
				que.push(e.to);
			}
		}
	}
	return level[t] != -1;
}
int dfs(int s, int t, int f)
{
	if (s == t || f == 0)
		return f;
	for (int &i = cur[s]; i < G[s].size(); i++) {
		edge e = E[G[s][i]];
		if (level[s] < level[e.to] && e.cap > e.flow) {
			int d = dfs(e.to, t, min(f, e.cap - e.flow));
			if (d > 0) {
				E[G[s][i]].flow += d;
				E[G[s][i] ^ 1].flow -= d;
				return d;
			}
		}
	}
	return 0;
}
int maxflow(int s, int t)
{
	int res = 0;
	while (bfs(s, t)) {
		int f;
		memset(cur, 0, sizeof(cur));
		while ((f = dfs(s, t, inf)) > 0)
			res += f;
	}
	return res;
}
int main()
{
	int n, f, d;
	while (~scanf("%d %d %d", &n, &f, &d)) {
		int s = 0, t = f + n + n + d + 1;
		E.clear();
		for (int i = 0; i <= t; i++) {
			G[i].clear();
		}
		int x;
		for (int i = 1; i <= f; i++) {
			scanf("%d", &x);
			add_edge(s, i, x);
		}
		for (int i = 1; i <= d; i++) {
			scanf("%d", &x);
			add_edge(f + n + n + i, t, x);
		}
		for (int i = 1; i <= n; i++) {
			scanf("%s", str);
			add_edge(f + i, f + n + i, 1);
			for (int j = 0; j < f; j++) {
				if (str[j] == 'Y') {
					add_edge(j + 1, f + i, 1); // f - p1
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			scanf("%s", str);
			for (int j = 0; j < d; j++) {
				if (str[j] == 'Y') {
					add_edge(f + n + i, f + n + n + j + 1, 1); // p2 - d
				}
			}
		}
		printf("%d\n", maxflow(s, t));
	}
	return 0;
}