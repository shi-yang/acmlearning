#include <bits/stdc++.h>
using namespace std;
const int N = 505;
const int inf = 0x3f3f3f3f;
int w[N][N];
int n;
int lx[N], ly[N];
int visx[N], visy[N], slack[N];
int linky[N];
bool match(int x)
{
	visx[x] = 1;
	for (int v = 1; v <= n; v++) {
		if (visy[v])
			continue;
		if (lx[x] + ly[v] - w[x][v] == 0) {
			visy[v] = 1;
			if (linky[v] == -1 || match(linky[v])) {
				linky[v] = x;
				return true;
			}
		} else {
			slack[v] = min(slack[v], lx[x] + ly[v] - w[x][v]);
		}
	}
	return false;
}
int km()
{
	memset(ly, 0, sizeof(ly));
	memset(linky, -1, sizeof(linky));
	for (int i = 1; i <= n; i++) {
		lx[i] = -inf;
		for (int j = 1; j <= n; j++) {
			lx[i] = max(lx[i], w[i][j]);
		}
	}
	for (int x = 1; x <= n; x++) {
		memset(slack, inf, sizeof(slack));
		for (;;) {
			memset(visx, 0, sizeof(visx));
			memset(visy, 0, sizeof(visy));
			if (match(x))
				break;
			int d = inf;
			for (int i = 1; i <= n; i++) {
				if (!visy[i])
					d = min(d, slack[i]);
			}
			for (int i = 1; i <= n; i++) {
				if (visx[i])
					lx[i] -= d;
				if (visy[i])
					ly[i] += d;
				else
					slack[i] -= d;
			}
		}
	}
	int res = 0;
	for (int i = 1; i <= n; i++) {
		res += lx[i] + ly[i];
	}
	return res;
}
int main()
{
	while (~scanf("%d", &n)) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				scanf("%d", &w[i][j]);
			}
		}
		int ans = km();
		for (int i = 1; i <= n; i++) {
			if (i != 1)
				putchar(' ');
			printf("%d", lx[i]);
		}
		putchar('\n');
		for (int i = 1; i <= n; i++) {
			if (i != 1)
				putchar(' ');
			printf("%d", ly[i]);
		}
		printf("\n%d\n", ans);
	}
	return 0;
}