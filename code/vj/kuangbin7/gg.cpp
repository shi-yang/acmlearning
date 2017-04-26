#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 50005;
int mi[maxn][32];
int mx[maxn][32];
int n, q;
int rmq(int l, int r, int c)
{
	int k = 0;
	while ((1 << (k + 1)) <= r - l + 1)	k++;
	if (c)
		return max(mx[l][k], mx[r - (1 << k) + 1][k]);
	return min(mi[l][k], mi[r - (1 << k) + 1][k]);
}
int main()
{
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		mi[i][0] = mx[i][0] = x;
	}
	for (int j = 1; (1 << j) <= n; j++) {
		for (int i = 1; i + (1 << j) - 1 <= n; i++) {
			mi[i][j] = min(mi[i][j - 1], mi[i + (1 << (j - 1))][j - 1]);
			mx[i][j] = max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
		}
	}
	while (q--) {
		int a, b;
		scanf("%d %d", &a, &b);
		int mxx = rmq(a, b, 1);
		int mii = rmq(a, b, 0);
		printf("%d\n", mxx - mii);
	}
	return 0;
}
