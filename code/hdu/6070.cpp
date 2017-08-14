#include <bits/stdc++.h>
using namespace std;
const int N = 60005;
const double eps = 1e-10;
double mi[N << 2];
double laze[N << 2];
int a[N];
int last[N];
void push_down(int rt)
{
	if (laze[rt]) {
		laze[rt << 1] += laze[rt];
		laze[rt << 1 | 1] += laze[rt];
		mi[rt << 1] += laze[rt];
		mi[rt << 1 | 1] += laze[rt];
		laze[rt] = 0;
	}
}
void build(int l, int r, int rt, double x)
{
	if (l == r) {
		mi[rt] = l * x;
		return;
	}
	int m = l + r >> 1;
	build(l, m, rt << 1, x);
	build(m + 1, r, rt << 1 | 1, x);
	mi[rt] = min(mi[rt << 1], mi[rt << 1 | 1]);
}
void update(int ll, int rr, double v, int l, int r, int rt)
{
	if (ll <= l && r <= rr) {
		laze[rt] += v;
		mi[rt] += v;
		return;
	}
	push_down(rt);
	int m = l + r >> 1;
	if (ll <= m)
		update(ll, rr, v, l, m, rt << 1);
	if (rr > m)
		update(ll, rr, v, m + 1, r, rt << 1 | 1);
	mi[rt] = min(mi[rt << 1], mi[rt << 1 | 1]);
}
double query(int ll, int rr, int l, int r, int rt)
{
	if (ll <= l && r <= rr) {
		return mi[rt];
	}
	push_down(rt);
	int m = l + r >> 1;
	double res = 1e9;
	if (ll <= m)
		res = min(res, query(ll, rr, l, m, rt << 1));
	if (rr > m)
		res = min(res, query(ll, rr, m + 1, r, rt << 1 | 1));
	return res;
}
int main()
{
	int t, n;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", a + i);
		}
		double low = 0, high = 1.0;
		while (high - low > eps) {
			double mid = (low + high) / 2;
			memset(laze, 0, sizeof(laze));
			memset(last, 0, sizeof(last));
			build(1, n, 1, mid);
			int ok = 0;
			for (int i = 1; i <= n; i++) {
				update(last[a[i]] + 1, i, 1, 1, n, 1);
				last[a[i]] = i;
				if (query(1, i, 1, n, 1) <= mid * (i + 1)) {
					ok = 1;
					break;
				}
			}
			if (ok)
				high = mid;
			else
				low = mid;
		}
		printf("%.9lf\n", low);
	}
	return 0;
}