#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100005;
int a[maxn];
int g[maxn][32];
int search(int l, int r, int n)
{
	int k = 0;
	while ((1 << (k + 1)) <= r - l + 1) k++;
	return __gcd(g[l][k], g[r - (1 << k) + 1][k]);
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", a + i);
			g[i + 1][0] = a[i];
		}
		for (int j = 1; (1 << j) <= n; j++) {
			for (int i = 1; i + (1 << j) - 1 <= n; j++) {
				g[i][j] = __gcd(g[i][j - 1], g[i + (1 << (j - 1))][j - 1]);
			}
		}
		int q;
		scanf("%d", &q);
		while (q--) {
			int l, r;
			scanf("%d %d", &l, &r);
			printf("%d\n", search(l, r, n));
		}
	}
	return 0;
}
