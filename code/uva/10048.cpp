#include <bits/stdc++.h>
using namespace std;
const int C = 105;
const int inf = 0x3f3f3f3f;
int dis[C][C];
int main()
{
	int s, c, q;
	int cas = 1;
	while (~scanf("%d %d %d", &c, &s, &q), c + s + q) {
		memset(dis, inf, sizeof(dis));
		for (int i = 0; i < s; i++) {
			int u, v, d;
			scanf("%d %d %d", &u, &v, &d);
			dis[u][v] = dis[v][u] = d;
		}
		for (int k = 1; k <= c; k++) {
			for (int i = 1; i <= c; i++) {
				for (int j = 1; j <= c; j++) {
					dis[i][j] = min(dis[i][j], max(dis[i][k], dis[k][j]));
				}
			}
		}
		if (cas != 1)
			putchar('\n');
		printf("Case #%d\n", cas++);
		while (q--) {
			int x, y;
			scanf("%d %d", &x, &y);
			if (dis[x][y] == inf) {
				printf("no path\n");
			} else {
				printf("%d\n", dis[x][y]);
			}
		}
	}
	return 0;
}