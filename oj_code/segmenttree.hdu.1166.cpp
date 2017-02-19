#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 50005;
int sum[maxn << 2];
void build(int l, int r, int rt)
{
	if (l == r) {
		scanf("%d", &sum[rt]);
	} else {
		int mid = (l + r) >> 1;
		build(l, mid, rt << 1);
		build(mid + 1, r, rt << 1 | 1);
		sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
	}
}
int query(int ll, int rr, int l, int r, int rt)
{
	if (ll <= l && r <= rr) {
		return sum[rt];
	}
	int ret = 0;
	int m = (l + r) >> 1;
	if (ll <= m) {
		ret += query(ll, rr, l, m, rt << 1);
	}
	if (rr > m) {
		ret += query(ll, rr, m + 1, r, rt << 1 | 1);
	}
	return ret;
}
void update(int x, int add, int l, int r, int rt)
{
	if (l == r) {
		sum[rt] += add;
	} else {
		int m = (l + r) >> 1;
		if (x <= m) {
			update(x, add, l, m, rt << 1);
		} else {
			update(x, add, m + 1, r, rt << 1 | 1);
		}
		sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
	}
}
int main()
{
	int tt, n;
	scanf("%d", &tt);
	for (int i = 1; i <= tt; i++) {
		scanf("%d", &n);
		build(1, n, 1);
		printf("Case %d:\n", i);
		char s[10];
		int a, b;
		while (~scanf("%s", s)) {
			if (s[0] == 'E') {
				break;
			} else {
				scanf("%d%d", &a, &b);
				if (s[0] == 'Q') {
					int ans = query(a, b, 1, n, 1);
					printf("%d\n", ans);
				} else if (s[0] == 'A') {
					update(a, b, 1, n, 1);
				} else if (s[0] == 'S') {
					update(a, -b, 1, n, 1);
				}
			}
		}
	}
	return 0;
}
