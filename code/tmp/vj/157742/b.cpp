#include <cstring>
#include <cmath>
#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;
const int maxn = 1005;
struct edge {
	int x, y;
} e[maxn];
double d[maxn][maxn];
int n;
double dis(int x, int y, int xx, int yy)
{
	return sqrt(double((x - xx) * (x - xx) + (y - yy) * (y - yy)));
}
void floyd()
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			d[j][i] = d[i][j] = dis(e[i].x, e[i].y, e[j].x, e[j].y);
		}
	}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				d[i][j] = min(d[i][j], max(d[i][k], d[k][j]));
			}
		}
	}
}
int main()
{
	int kase = 1;
	while (~scanf("%d", &n) && n) {
		memset(d, 0, sizeof(d));
		for (int i = 0; i < n; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			e[i].x = x, e[i].y = y;
		}
		printf("Scenario #%d\n", kase++);
		floyd();
		double ans = d[0][1];
		printf("Frog Distance = %.3lf\n\n", ans);
	}
	return 0;
}
