#include <bits/stdc++.h>
using namespace std;

const int N = 105;
const int inf = 0x3f3f3f3f;
int G[N][N];
int main()
{
	memset(G, inf, sizeof(G));
	for (int i = 0; i < N; i++)
		G[i][i] = 0;
	int a, b, mx = 0;
	for (int cas = 1;; cas++) {
		while (~scanf("%d %d", &a, &b), a + b) {
			G[a][b] = 1;
			mx = max(mx, max(a, b));
		}
		for (int k = 1; k <= mx; k++) {
			for (int i = 1; i <= mx; i++) {
				for (int j = 1; j <= mx; j++) {
					G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
				}
			}
		}
		int sum = 0, cnt = 0;
		for (int i = 1; i <= mx; i++) {
			for (int j = 1; j <= mx; j++) {
				if (i == j || G[i][j] == inf)
					continue;
				cnt++;	
				sum += G[i][j];
			}
		}
		double ans = 1.0 * sum / cnt;
		printf("Case %d: average length between pages = %.3f clicks\n", cas, ans);

		mx = 0;
		memset(G, inf, sizeof(G));
		for (int i = 0; i < N; i++)
			G[i][i] = 0;
		scanf("%d %d", &a, &b);
		if (a + b == 0)  {
			break;
		} else {
			mx = max(mx, max(a, b));
			G[a][b] = 1;
		} 
	}
	return 0;
}