#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int sum[maxn << 2];
int add[maxn << 2];
void push_up(int rt)
{
	sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}
void push_down(int rt, int n)
{
	if (add[rt]) {
		add[rt << 1] = add[rt];
		add[rt << 1 | 1] = add[rt];
		sum[rt << 1] = add[rt] * (n - (n >> 1));
		sum[rt << 1 | 1] = add[rt] * (n >> 1);
		add[rt] = 0;
	}
}
void build(int l, int r, int rt)
{
	if (l == r) {
		sum[rt] = 1;
	} else {
		int m = (l + r) >> 1;
		build(l, m, rt << 1);
		build(m + 1, r, rt << 1 | 1);
		push_up(rt);
	}
}
void update(int ll, int rr, int x, int l, int r, int rt)
{
	if (ll <= l && r <= rr) {
		sum[rt] = x * (r - l + 1);
		add[rt] = x;
		return ;
	}
	push_down(rt, r - l + 1);
	int m = (l + r) >> 1;
	if (ll <= m)
		update(ll, rr, x, l, m, rt << 1);
	if (rr > m)
		update(ll, rr, x, m + 1, r, rt << 1 | 1);
	push_up(rt);
}
int main()
{
	int t;
	scanf("%d", &t);
	int n, q;
	int kase = 1;
	while (t--) {
		scanf("%d %d", &n, &q);
		memset(add, 0, sizeof(add));
		build(1, n, 1);
		while (q--) {
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			update(a, b, c, 1, n, 1);
		}
		printf("Case %d: The total value of the hook is %d.\n", kase++, sum[1]);
	}
	return 0;
}
