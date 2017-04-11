#include <iostream>
#include <cstdio>
using namespace std;
typedef long long lint;
const int maxn = 100005;
lint sum[maxn << 2];
lint add[maxn << 2];
lint n, q;
void push_down(lint rt, lint num)
{
	if (add[rt]) {
		add[rt << 1] += add[rt];
		add[rt << 1 | 1] += add[rt];
		sum[rt << 1] += add[rt] * (num - (num >> 1));
		sum[rt << 1 | 1] += add[rt] * (num >> 1);
		add[rt] = 0;
	}
}
void build(lint l, lint r, lint rt)
{
	if (l == r) {
		scanf("%lld", &sum[rt]);
	} else {
		lint m = (l + r) >> 1;
		build(l, m, rt << 1);
		build(m + 1, r, rt << 1 | 1);
		sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
	}
}
void update(lint ll, lint rr, lint x, lint l, lint r, lint rt)
{
	if (ll <= l && r <= rr) {
		sum[rt] += (r - l + 1) * x;
		add[rt] += x;
		return ;
	}
	push_down(rt, r - l + 1);
	lint m = (l + r) >> 1;
	if (ll <= m)
		update(ll, rr, x, l, m, rt << 1);
	if (rr > m)
		update(ll, rr, x, m + 1, r, rt << 1 | 1);
	sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}
lint query(lint ll, lint rr, lint l, lint r, lint rt)
{
	if (ll <= l && r <= rr) {
		return sum[rt];
	}
	push_down(rt, r - l + 1);
	lint res = 0;
	lint m = (l + r) >> 1;
	if (ll <= m)
		res += query(ll, rr, l, m, rt << 1);
	if (rr > m)
		res += query(ll, rr, m + 1, r, rt << 1 | 1);
	sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
	return res;
}
int main()
{
	scanf("%lld %lld", &n, &q);
	build(1, n, 1);
	char str[5];
	while (q--) {
		lint a, b, c;
		scanf("%s", str);
		if (str[0] == 'Q') {
			scanf("%lld %lld", &a, &b);
			lint ans = query(a, b, 1, n, 1);
			printf("%lld\n", ans);
		} else {
			scanf("%lld %lld %lld", &a, &b, &c);
			update(a, b, c, 1, n, 1);
		}
	}
	return 0;
}
