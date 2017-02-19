//线段树单点更新
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
	if (ll <= l && r <= rr)
		return sum[rt];
	int ret = 0;
	int m = (l + r) >> 1;
	if (ll <= m)
		ret += query(ll, rr, l, m, rt << 1);
	if (rr > m)
		ret += query(ll, rr, m + 1, r, rt << 1 | 1);
	return ret;
}
void update(int x, int add, int l, int r, int rt)
{
	if (l == r) {
		sum[rt] += add;
	} else {
		int m = (l + r) >> 1;
		if (x <= m)
			update(x, add, l, m, rt << 1);
		else
			update(x, add, m + 1, r, rt << 1 | 1);
		sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
	}
}


//线段树区间更新
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
