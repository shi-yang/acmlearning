#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 100010;
int n, q, s, sz;
int cnt, head[N], f[N], dep[N], bl[N], pos[N], v[N], size[N];
int son[N];
struct edge {
	int from, to, w;
} e[N];
int sum[N << 2];
struct node {
	int to, next;
} nc[N << 1];
void add_edge(int u, int v)
{
	nc[++cnt].to = v;
	nc[cnt].next = head[u];
	head[u] = cnt;
}
void dfs1(int x)
{
	size[x] = 1;
	for (int i = head[x]; i; i = nc[i].next) {
		if (f[x] == nc[i].to)
			continue;
		f[nc[i].to] = x;
		dep[nc[i].to] = dep[x] + 1;
		dfs1(nc[i].to);
		size[x] += size[nc[i].to];
		if (size[son[x]] < size[nc[i].to])
			son[x] = nc[i].to;
	}
}
void dfs2(int x, int chain)
{
	bl[x] = chain;
	pos[x] = ++sz;
	if (son[x])
		dfs2(son[x], chain);
	else
		return;
	for (int i = head[x]; i; i = nc[i].next) {
		if (son[x] != nc[i].to && nc[i].to != f[x])
			dfs2(nc[i].to, nc[i].to);
	}
}
void update(int p, int v, int l, int r, int rt)
{
	if (l == r) {
		sum[rt] = v;
		return;
	}
	int m = (l + r) >> 1;
	if (p <= m)
		update(p, v, l, m, rt << 1);
	else
		update(p, v, m + 1, r, rt << 1 | 1);
	sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}
int query(int ll, int rr, int l, int r, int rt)
{
	if (ll <= l && r <= rr)
		return sum[rt];
	int m = (l + r) >> 1;
	int res = 0;
	if (ll <= m)
		res += query(ll, rr, l, m, rt << 1);
	if (rr > m)
		res += query(ll, rr, m + 1, r, rt << 1 | 1);
	return res;
}
int solvesum(int x, int y)
{
	int res = 0;
	while (bl[x] != bl[y]) {
		if (dep[bl[x]] < dep[bl[y]])
			swap(x, y);
		res += query(pos[bl[x]], pos[x], 1, n, 1);
		x = f[bl[x]];
	}
	if (x == y)
		return res;
	if (pos[x] > pos[y])
		swap(x, y);
	return res + query(pos[son[x]], pos[y], 1, n, 1);
}
int main()
{
	scanf("%d %d %d", &n, &q, &s);
	for (int i = 1; i < n; i++) {
		scanf("%d %d %d", &e[i].from, &e[i].to, &e[i].w);
		add_edge(e[i].from, e[i].to);
		add_edge(e[i].to, e[i].from);
	}
	dfs1(1);
	dfs2(1, 1);
	for (int i = 1; i < n; i++) {
		if (dep[e[i].from] < dep[e[i].to])
			swap(e[i].from, e[i].to);
		update(pos[e[i].from], e[i].w, 1, n, 1);
	}
	while (q--) {
		int x;
		scanf("%d", &x);
		if (x) {
			int a, b;
			scanf("%d %d", &a, &b);
			update(pos[e[a].from], b, 1, n, 1);
		} else {
			int y;
			scanf("%d", &y);
			printf("%d\n", solvesum(s, y));
			s = y;
		}
	}
	return 0;
}