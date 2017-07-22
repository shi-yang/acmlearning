#include <bits/stdc++.h>

using namespace std;

const int inf = 0x7777777;
const int N = 10005;

int n;
struct edge {
	int to, cost, next;
} e[N << 1];
int mx[N << 2];
int cnt, head[N], dep[N], bl[N], size[N], fa[N], pos[N];
int v[N];
int sz;
void add_edge(int from, int to, int cost)
{
	e[++cnt].to = to, e[cnt].cost = cost, e[cnt].next = head[from], head[from] = cnt;
	e[++cnt].to = from, e[cnt].cost = cost, e[cnt].next = head[to], head[to] = cnt;
}
void dfs1(int x)
{
	size[x] = 1;
	for (int i = head[x]; i; i = e[i].next) {
		if (fa[x] == e[i].to)
			continue;
		fa[e[i].to] = x;
		dep[e[i].to] = dep[x] + 1;
		v[e[i].to] = e[i].cost;
		dfs1(e[i].to);
		size[x] += size[e[i].to];
	}
}
void dfs2(int x, int chain)
{
	int k = 0;
	pos[x] = ++sz;
	bl[x] = chain;
	for (int i = head[x]; i; i = e[i].next) {
		if (dep[e[i].to] > dep[x] && size[k] < size[e[i].to])
			k = e[i].to;
	}
	if (k == 0)
		return;
	dfs2(k, chain);
	for (int i = head[x]; i; i = e[i].next) {
		if (dep[e[i].to] > dep[x] && k != e[i].to)
			dfs2(e[i].to, e[i].to);
	}
}
void update(int p, int v, int l, int r, int rt)
{
	if (l == r) {
		mx[rt] = v;
		return;
	}
	int m = (l + r) >> 1;
	if (p <= m)
		update(p, v, l, m, rt << 1);
	else
		update(p, v, m + 1, r, rt << 1 | 1);
	mx[rt] = max(mx[rt << 1], mx[rt << 1 | 1]);
}
int query(int ll, int rr, int l, int r, int rt)
{
	if (ll <= l && r <= rr)
		return mx[rt];
	int m = (l + r) >> 1;
	int res = -inf;
	if (ll <= m)
		res = max(res, query(ll, rr, l, m, rt << 1));
	if (rr > m)
		res = max(res, query(ll, rr, m + 1, r, rt << 1 | 1));
	return res;
}
int solve(int x, int y)
{
	int res = -inf;
	while (bl[x] != bl[y]) {
		if (dep[bl[x]] < dep[bl[y]])
			swap(x, y);
		res = max(res, query(pos[bl[x]], pos[x], 1, n, 1));
		x = fa[bl[x]];
	}
	if (pos[x] > pos[y])
		swap(x, y);
	return max(res, query(pos[x], pos[y], 1, n, 1));
}
int main()
{
	int tt;
	scanf("%d", &tt);
	while (tt--) {
		scanf("%d", &n);
		cnt = sz = 0;
		memset(head, 0, sizeof(head));
		for (int i = 1; i < n; i++) {
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			add_edge(a, b, c);
		}
		dfs1(1);
		dfs2(1, 1);
		v[1] = -inf;
		for (int i = 1; i <= n; i++) {
			update(pos[i], v[i], 1, n, 1);
		}
		char str[10];
		int x, y;
		while (~scanf("%s", str) && str[0] != 'D') {
			scanf("%d %d", &x, &y);
			if (str[0] == 'C') {
				pos[x] = y;
				update(pos[x], y, 1, n, 1);
			} else {
				printf("%d\n", solve(x, y));
			}
		}
	}
	return 0;
}