#include <bits/stdc++.h>
using namespace std;

const int inf = 0x3f3f3f3f;
const int N = 255 * 255;
int a[N], g[N], s[N], d[N];
int main()
{
	int tt, kase = 1;
	scanf("%d", &tt);
	while (tt--) {
		int n, p, q;
		memset(a, 0, sizeof(a));
		scanf("%d %d %d", &n, &p, &q);
		for (int i = 1; i <= p + 1; i++) {
			int x;
			scanf("%d", &x);
			a[x] = i;
		}
		int cnt = 0;
		for (int i = 0; i < q + 1; i++) {
			int x; scanf("%d", &x);
			if (a[x])
				s[cnt++] = a[x];
		}
		memset(g, inf, sizeof(g));
		int ans = 0;
		for (int i = 0; i < cnt; i++) {
			int k = lower_bound(g + 1, g + 1 + cnt, s[i]) - g;
			d[i] = k;
			g[k] = s[i];
			ans = max(ans, d[i]);
		}
		printf("Case %d: %d\n", kase++, ans);
	}
	return 0;
}
