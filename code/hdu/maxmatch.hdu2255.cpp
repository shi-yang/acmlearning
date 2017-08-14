#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 305;
int w[N][N];
int slack[N];
int visx[N], visy[N];
int lx[N], ly[N];
int link[N];
int n;
bool match(int u)
{
	visx[u] = 1;
	for (int y = 0; y < n; y++) {
		if (visy[y])
			continue;
		int t = lx[u] + ly[y] - w[u][y];
		if (!t) {
			visy[y] = 1;
			if (!~link[y] || match(link[y])) {
				link[y] = u;
				return true;
			}
		} else {
			slack[y] = min(slack[y], t);
		}
	}
	return false;
}
void km()
{
	memset(link, -1, sizeof(link));
	memset(ly, 0, sizeof(ly));
	for (int i = 0; i < n; i++) {
		lx[i] = 0;
		for (int j = 0; j < n; j++) {
			lx[i] = max(lx[i], w[i][j]);
		}
	}
	for (int x = 0; x < n; x++) {
		memset(slack, inf, sizeof(slack));
		for (;;) {
			memset(visx, 0, sizeof(visx));
			memset(visy, 0, sizeof(visy));
			if (match(x)) {
				break;
			}
			int d = inf;
			for (int i = 0; i < n; i++) {
				if (!visy[i])
					d = min(d, slack[i]);
			}
			for (int i = 0; i < n; i++) {
				if (visx[i])
					lx[i] -= d;
				if (visy[i])
					ly[i] += d;
				else
					slack[i] -= d;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += w[link[i]][i];
	}
	printf("%d\n", ans);
}
int main()
{
	while (~scanf("%d", &n)) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int x;
				scanf("%d", &x);
				w[i][j] = x;
			}
		}
		km();
	}
	return 0;
}