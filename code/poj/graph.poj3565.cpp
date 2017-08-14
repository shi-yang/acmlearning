#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int N = 105;
const double inf = 1e9;
const double eps = 1e-8;
int n;
struct Point {
	int x, y;
} ant[N], apple[N];
double d[N][N];
double lx[N], ly[N];
int linky[N], visx[N], visy[N];
double slack[N];
double dis(Point a, Point b)
{
	return sqrt(1.0 * ((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)));
}
bool match(int u)
{
	visx[u] = 1;
	for (int i = 1; i <= n; i++) {
		if (visy[i])
			continue;
		double t = lx[u] + ly[i] - d[u][i];
		if (fabs(t) < eps) {
			visy[i]++;
			if (linky[i] == -1 || match(linky[i])) {
				linky[i] = u;
				return true;
			}
		} else {
			slack[i] = min(slack[i], t);
		}
	}
	return false;
}
void km()
{
	memset(linky, -1, sizeof(linky));
	memset(ly, 0, sizeof(ly));
	for (int i = 1; i <= n; i++) {
		lx[i] = -inf;
		for (int j = 1; j <= n; j++) {
			lx[i] = max(lx[i], d[i][j]);
		}
	}
	for (int x = 1; x <= n; x++) {
		for (int j = 1; j <= n; j++)
			slack[j] = inf;
		for (;;) {
			memset(visx, 0, sizeof(visx));
			memset(visy, 0, sizeof(visy));
			if (match(x)) {
				break;
			}
			double d = inf;
			for (int i = 1; i <= n; i++) {
				if (!visy[i] && d > slack[i])
					d = slack[i];
			}
			for (int i = 1; i <= n; i++) {
				if (visx[i])
					lx[i] -= d;
			}
			for (int i = 1; i <= n; i++) {
				if (visy[i])
					ly[i] += d;
				else
					slack[i] -= d;
			}
		}
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &ant[i].x, &ant[i].y);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &apple[i].x, &apple[i].y);
	}
	memset(d, inf, sizeof(d));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			d[i][j] = -dis(ant[i], apple[j]);
		}
	}
	km();
	int ans[N];
	for (int i = 1; i <= n; i++) {
		ans[linky[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}