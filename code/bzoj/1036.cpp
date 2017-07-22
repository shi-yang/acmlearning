#include <bits/stdc++.h>
using namespace std;

const int inf = 0x7777777;
const int N = 30005;

struct edge {
	int to, next;
} e[N];
struct seg {
	int mx, sum;
} t[N << 2];
int n;
int cnt, sz, head[N], size[N], fa[N], dep[N], bl[N], pos[N];
int v[N];
void add_edge(int u, int v)
{
	e[++cnt].to = v, e[cnt].next = head[u], head[u] = cnt;
	e[++cnt].to = u, e[cnt].next = head[v], head[v] = cnt;
}
void dfs1(int x)
{
	size[x] = 1;
	for (int i = head[x]; i; i = e[i].next) {
		if (fa[x] == e[i].to)
			continue;
		fa[e[i].to] = x;
		dep[e[i].to] = dep[x] + 1;
		dfs1(e[i].to);
		size[x] += size[e[i].to];
	}
}
void dfs2(int x, int chain)
{
	bl[x] = chain;
	pos[x] = ++sz;
	int k = 0;
	for (int i = head[x]; i; i = e[i].next) {
		if (dep[e[i].to] > dep[x] && size[e[i].to] > size[k])
			k = e[i].to;
	}
	if (k == 0)
		return;
	dfs2(k, chain);
	for (int i = head[x]; i; i = e[i].next) {
		if (dep[e[i].to] > dep[x] && k != e[i].to) {
			dfs2(e[i].to, e[i].to);
		}
	}
}
void update(int p, int v, int l, int r, int rt)
{
	if (l == r) {
		t[rt].mx = t[rt].sum = v;
		return;
	}
	int m = (l + r) >> 1;
	if (p <= m)
		update(p, v, l, m, rt << 1);
	else
		update(p, v, m + 1, r, rt << 1 | 1);
	t[rt].sum = t[rt << 1].sum + t[rt << 1 | 1].sum;
	t[rt].mx = max(t[rt << 1].mx, t[rt << 1 | 1].mx);
} 
int querysum(int ll, int rr, int l, int r, int rt)
{
	if (ll <= l && r <= rr) {
		return t[rt].sum;
	}
	int m = (l + r) >> 1;
	int res = 0;
	if (ll <= m)
		res += querysum(ll, rr, l, m, rt << 1);
	if (rr > m)
		res += querysum(ll, rr, m + 1, r, rt << 1 | 1);
	return res;
}
int querymx(int ll, int rr, int l, int r, int rt)
{
	if (ll <= l && r <= rr) {
		return t[rt].mx;
	}
	int m = (l + r) >> 1;
	int mx = -inf;
	if (ll <= m)
		mx = max(mx, querymx(ll, rr, l, m, rt << 1));
	if (rr > m)
		mx = max(mx, querymx(ll, rr, m + 1, r, rt << 1 | 1));
	return mx;
}
int solvemx(int x, int y)
{
	int res = -inf;
	while (bl[x] != bl[y]) {
		if (dep[bl[x]] < dep[bl[y]]) {
			swap(x, y);
		}
		res = max(res, querymx(pos[bl[x]], pos[x], 1, n, 1));
		x = fa[bl[x]];
	}
	if (pos[x] > pos[y])
		swap(x, y);
	res = max(res, querymx(pos[x], pos[y], 1, n, 1));
	return res;
}
int solvesum(int x, int y)
{
	int res = 0;
	while (bl[x] != bl[y]) {
		if (dep[bl[x]] < dep[bl[y]]) {
			swap(x, y);
		}
		res += querysum(pos[bl[x]], pos[x], 1, n, 1);
		x =fa[bl[x]];
	}
	if (pos[x] > pos[y])
		swap(x, y);
	res += querysum(pos[x], pos[y], 1, n, 1);
	return res;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		add_edge(u, v);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", v + i);
	}
	dfs1(1);
	dfs2(1, 1);
	for (int i = 1; i <= n; i++) {
		update(pos[i], v[i], 1, n, 1);
	}
	int q;
	scanf("%d", &q);
	while (q--) {
		char s[10];
		int x, y;
		scanf("%s %d %d", s, &x, &y);
		if (s[0] == 'C') {
			v[x] = y;
			update(pos[x], y, 1, n, 1);
		} else if (s[1] == 'M') {
			printf("%d\n", solvemx(x, y));
		} else {
			printf("%d\n", solvesum(x, y));
		}
	}
	return 0;
}