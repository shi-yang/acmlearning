#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
int n, m;
struct edge {
	int to, next;
} e[N << 1];
int size[N], f[N], dep[N], son[N], top[N];
int head[N];
int cnt;
void add_edge(int u, int v)
{
	e[++cnt].to = v;
	e[cnt].next = head[u];
	head[u] = cnt;
}
void dfs1(int u)
{
	size[u] = 1;
	for (int i = head[u]; i; i = e[i].next) {
		if (f[u] == e[i].to)
			continue;
		f[e[i].to] = u;
		dep[e[i].to] = dep[u] + 1;
		dfs1(e[i].to);
		size[u] += size[e[i].to];
		if (size[son[u]] < size[e[i].to])
			son[u] = e[i].to;
	}
}
void dfs2(int u, int b)
{
	top[u] = b;
	if (son[u]) {
		dfs2(son[u], b);
	} else {
		return;
	}
	for (int i = head[u]; i; i = e[i].next) {
		if (son[u] != e[i].to && dep[e[i].to] > dep[u]) {
			dfs2(e[i].to, e[i].to);
		}
	}
}
int lca(int x, int y)
{
	while (top[x] ^ top[y]) {
		if (dep[top[x]] < dep[top[y]])
			swap(x, y);
		x = f[top[x]];
	}
	return dep[x] < dep[y] ? x : y;
}

int dis(int a, int b, int r)
{
	return dep[a] + dep[b] - 2 * dep[r];
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		add_edge(u, v);
		add_edge(v, u);
	}
	dfs1(1);
	dfs2(1, 0);
	while (m--) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		int x1 = lca(a, b);
		int d1 = dis(x1, c, lca(x1, c)) + dis(a, b, x1);

		int x2 = lca(b, c);
		int d2 = dis(x2, a, lca(x2, a)) + dis(b, c, x2);

		int x3 = lca(a, c);
		int d3 = dis(x3, b, lca(x3, b)) + dis(a, c, x3);
		if (d1 <= d2 && d1 <= d3) {
			printf("%d %d\n", x1, d1);
		} else if (d2 <= d1 && d2 <= d3) {
			printf("%d %d\n", x2, d2);
		} else if (d3 <= d1 && d3 <= d2) {
			printf("%d %d\n", x3, d3);
		}
	}
	return 0;
}