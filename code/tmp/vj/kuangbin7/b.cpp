#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 200005;
int sum[maxn << 2];
int n, m;
void build(int l, int r, int rt)
{
	if (l == r) {
		scanf("%d", &sum[rt]);
	} else {
		int m = (l + r) >> 1;
		build(l, m, rt << 1);
		build(m + 1, r, rt << 1 | 1);
		sum[rt] = max(sum[rt << 1], sum[rt << 1 | 1]);
	}
}
int query(int ll, int rr, int l, int r, int rt)
{
	if (ll <= l && r <= rr) {
		return sum[rt];
	}
	int m = (l + r) >> 1;
	int res = 0;
	if (ll <= m)
		res = max(res, query(ll, rr, l, m, rt << 1));
	if (rr > m)
		res = max(res, query(ll, rr, m + 1, r, rt << 1 | 1));
	return res;
}
void update(int x, int v, int l, int r, int rt)
{
	if (l == r) {
		sum[rt] = v;
		return ;
	}
	int m = (l + r) >> 1;
	if (x <= m)
		update(x, v, l, m, rt << 1);
	else
		update(x, v, m + 1, r, rt << 1 | 1);
	sum[rt] = max(sum[rt << 1], sum[rt << 1 | 1]);
}
int main()
{
	while (~scanf("%d %d", &n, &m)) {
		memset(sum, 0, sizeof(sum));
		build(1, n, 1);
		char str[5];
		int a, b;
		while (m--) {
			scanf("%s %d %d", str, &a, &b);
			if (str[0] == 'Q') {
				int ans = query(a, b, 1, n, 1);
				printf("%d\n", ans);
			} else {
				update(a, b, 1, n, 1);
			}
		}
	}
	return 0;
}
