#include <bits/stdc++.h>
using namespace std;
const int N = 105;
struct Point {
	double x, y;
} p[N];
struct edge {
	int from, to;
	double dis;
	bool operator < (const edge &a) const {
		return dis < a.dis;
	}
} e[N * N];
int f[N];
int root(int x)
{
	return x == f[x] ? x : f[x] = root(f[x]);
}
double dis(Point a, Point b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i <= n; i++) {
			f[i] = i;
		}
		for (int i = 0; i < n; i++) {
			scanf("%lf %lf", &p[i].x, &p[i].y);
		}
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j)
					continue;
				e[cnt++] = (edge){i, j, dis(p[i], p[j])};
			}
		}
		sort(e, e + cnt);
		double ans = 0;
		for (int i = 0; i < cnt; i++) {
			int x = root(e[i].from), y = root(e[i].to);
			if (x != y) {
				f[x] = y;
				ans += e[i].dis;
			}
		}
		printf("%.2lf\n", ans);
		if (t)
			puts("");
	}
	return 0;
}