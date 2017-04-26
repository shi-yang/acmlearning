#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 50005;
struct edge {
	int mi, mx;
} e[maxn << 2];
void pushup(int rt)
{
	e[rt].mi = min(e[rt << 1].mi, e[rt << 1 | 1].mi);
	e[rt].mx = max(e[rt << 1].mx, e[rt << 1 | 1].mx);
}
void build(int l, int r, int rt)
{
	if (l == r) {
		int x;
		scanf("%d", &x);
		e[rt].mi = e[rt].mx = x;
	} else {
		int m = (l + r) >> 1;
		build(l, m, rt << 1);
		build(m + 1, r, rt << 1 | 1);
		pushup(rt);
	}
}
int query(int ll, int rr, int l, int r, int rt, int c)
{
	if (ll <= l && r <= rr) {
		if (c)	return e[rt].mx;
		else	return e[rt].mi;
	}
	int m = (l + r) >> 1;
	if (c) {
		int ans = 0;
		if (ll <= m)
			ans = max(ans, query(ll, rr, l, m, rt << 1, c));
		if (rr > m)
			ans = max(ans, query(ll, rr, m + 1, r, rt << 1 | 1, c));
		return ans;
	} else {
		int ans = 1e9;
		if (ll <= m)
			ans = min(ans, query(ll, rr, l, m, rt << 1, c));
		if (rr > m)
			ans = min(ans, query(ll, rr, m + 1, r, rt << 1 | 1, c));
		return ans;
	}
}
int main()
{
	int n, q;
	scanf("%d %d", &n, &q);
	build(1, n, 1);
	while (q--) {
		int a, b;
		scanf("%d%d", &a, &b);
		int mx = query(a, b, 1, n, 1, 1);
		int mi = query(a, b, 1, n, 1, 0);
		printf("%d\n", mx - mi);
	}
	return 0;
}
