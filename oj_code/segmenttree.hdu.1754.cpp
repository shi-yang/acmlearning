#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 200005;
int sum[maxn << 2];
void build(int l, int r, int rt)
{
	if (l == r) {
		scanf("%d", &sum[rt]);
		return ;
	}
	int m = (l + r) >> 1;
	build(l, m, rt << 1);
	build(m + 1, r, rt << 1 | 1);
	sum[rt] = max(sum[rt << 1], sum[rt << 1 | 1]);
}
int query(int ll, int rr, int l, int r, int rt)
{
	if (ll <= l && r <= rr) {
		return sum[rt];
	}
	int ans = -1;
	int m = (l + r) >> 1;
	if (ll <= m) {
		ans = max(ans, query(ll, rr, l, m, rt << 1));
	}
	if (rr > m) {
		ans = max(ans, query(ll, rr, m + 1, r, rt << 1 | 1));
	}
	return ans;
}
void update(int x, int y, int l, int r, int rt)
{
	if (l == r) {
		sum[rt] = y;
		return ;
	}
	int m = (l + r) >> 1;
	if (x <= m)
		update(x, y, l, m, rt << 1);
	else
		update(x, y, m + 1, r, rt << 1 | 1);
	sum[rt] = max(sum[rt << 1], sum[rt << 1 | 1]);
}
int main()
{
	int n, m;
	while (scanf("%d%d", &n, &m) != EOF) {
		build(1, n, 1);
		for (int i = 1; i <= m; i++) {
			char str;
			int x, y;
			cin >> str >> x >> y;
			if (str == 'Q') {
				printf("%d\n", query(x, y, 1, n, 1));
			} else {
				update(x, y, 1, n, 1);
			}
		}
	}
	return 0;
}
