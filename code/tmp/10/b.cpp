#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1234 * 1234;
struct edge {
	int l, r;
	bool operator < (const edge & a) const {
		if (l != a.l)
			return l < a.l;
		return r < a.r;
	}
} e[maxn];
int c[maxn];
int n, m, k;
inline int lowbit(int x)
{
	return x & -x;
}
inline int sum(int x)
{
	int res = 0;
	while (x > 0) {
		res += c[x];
		x -= lowbit(x);
	}
	return res;
}
inline void add(int x, int v)
{
	while (x <= m) {
		c[x] += v;
		x += lowbit(x);
	}
}
int main()
{
	int t;
	int kase = 1;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d %d", &n, &m, &k);
		for (int i = 0; i < k; i++) {
			scanf("%d %d", &e[i].l, &e[i].r);
		}
		sort(e, e + k);
		memset(c, 0, sizeof(c));
		long long ans = 0;
		for (int i = 0; i < k; i++) {
			add(e[i].r, 1);
			ans += sum(m) - sum(e[i].r);
		}
		printf("Test case %d: %lld\n", kase++, ans);
	}
	return 0;
}
