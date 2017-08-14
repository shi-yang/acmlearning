#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
struct edge {
	int to, next;
}e[N << 1];
int head[N], cnt;
int df[N], dep[N], size[N], top[N], son[N];
int f[N], same[N];
long long cost[N];
int num[N];
int n, m;
struct line {
	int a, b, c, d, w;
	bool operator < (const line &op) const {
		return w < op.w;
	}
} l[N];
void add_edge(int u, int v)
{
	e[++cnt].to = v, e[cnt].next = head[u], head[u] = cnt;
}
void dfs1(int u)
{
	size[u] = 1;
	for (int i = head[u]; i; i = e[i].next) {
		if (e[i].to == df[u])
			continue;
		df[e[i].to] = u;
		dep[e[i].to] = dep[u] + 1;
		dfs1(e[i].to);
		size[u] += size[e[i].to];
		if (size[son[u]] < size[e[i].to])
			son[u] = e[i].to;
	}
}
void dfs2(int u, int bl)
{
	top[u] = bl;
	if (!son[u])
		return;
	dfs2(son[u], bl);
	for (int i = head[u]; i; i = e[i].next) {
		if (son[u] != e[i].to && df[u] != e[i].to)
			dfs2(e[i].to, e[i].to);
	}
}
int root(int x)
{
	return x == f[x] ? x : f[x] = root(f[x]);
}
void add(int x, int y, int w)
{
	x = root(x), y = root(y);
	if (x != y) {
		f[x] = y;
		num[y] += num[x];
		cost[y] += cost[x] + w;
	}
}
int finds(int x)
{
	return x == same[x] ? x : same[x] = finds(same[x]);
}
void link(int x, int y, int w)
{
	int a = x, b = y;
	while (top[x] ^ top[y]) {
		if (dep[top[x]] < dep[top[y]])
			swap(x, y);
		x = df[top[x]];
	}
	int lca = dep[x] < dep[y] ? x : y;
	for (;;) {
		a = finds(a);
		if (dep[a] <= dep[lca])
			break;
		add(a, df[a], w);
		same[a] = df[a];
	}
	for (;;) {
		b = finds(b);
		if (dep[b] <= dep[lca])
			break;
		add(b, df[b], w);
		same[b] = df[b];
	}
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		memset(head, 0, sizeof(head));
		cnt = 0;
		for (int i = 1; i < n; i++) {
			int u, v;
			scanf("%d %d", &u, &v);
			add_edge(u, v);
			add_edge(v, u);
		}
		memset(son, 0, sizeof(son));
		memset(df, 0, sizeof(df));
		dfs1(1);
		dfs2(1, 1);
		for (int i = 0; i < m; i++) {
			scanf("%d %d %d %d %d", &l[i].a, &l[i].b, &l[i].c, &l[i].d, &l[i].w);
		}
		sort(l, l + m);
		for (int i = 1; i <= n; i++) {
			same[i] = f[i] = i;
			num[i] = 1;
		}
		memset(cost, 0, sizeof(cost));
		for (int i = 0; i < m; i++) {
			link(l[i].a, l[i].b, l[i].w);
			link(l[i].c, l[i].d, l[i].w);
			add(l[i].a, l[i].c, l[i].w);
		}
		int k = root(1);
		printf("%d %lld\n", num[k], cost[k]);
	}
	return 0;
}