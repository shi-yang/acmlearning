#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 105;
int n, m;
int d[maxn][maxn];
int tmp[maxn];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		d[a][b] = 1;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				d[i][j] |= d[i][k] & d[k][j];
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int x = 0, y = 0;
		for (int j = 1; j <= n; j++) {
			if (i != j) {
				x += d[i][j];
				y += d[j][i];
			}
		}
		if (x + y == n - 1) {
			ans++;
		}
	}
	printf("%d\n", ans);

	return 0;
}
