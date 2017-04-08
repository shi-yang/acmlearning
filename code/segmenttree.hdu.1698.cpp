#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 100005;
int sum[maxn << 2];
int laz[maxn << 2];
void pushDown(int rt, int num)
{
	if (laz[rt]) {
		laz[rt << 1] = laz[rt << 1 | 1] = laz[rt];
		sum[rt << 1] = (num - (num >> 1)) * laz[rt];
		sum[rt << 1 | 1] = (num >> 1) * laz[rt];
		laz[rt] = 0;
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
		sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
	}
}
void update(int ll, int rr, int v, int l, int r, int rt)
{
	if (ll <= l && r <= rr) {
		laz[rt] = v;
		sum[rt] = v * (r - l + 1);
	} else {
		pushDown(rt, r - l + 1);
		int m = (l + r) >> 1;
		if (ll <= m)
			update(ll, rr, v, l, m, rt << 1);
		if (rr > m)
			update(ll, rr, v, m + 1, r, rt << 1 | 1);
		sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
	}
}
int main()
{
	int tt;
	scanf("%d", &tt);
	for (int qq = 1; qq <= tt; qq ++) {
		int n, q;
		scanf("%d%d", &n, &q);
		memset(laz, 0, sizeof(laz));
		build(1, n, 1);
		while (q--) {
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			update(a, b, c, 1, n, 1);
		}
		int ans = sum[1];
		printf("Case %d: The total value of the hook is %d.\n", qq, ans);
	}
}
