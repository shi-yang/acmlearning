#include <bits/stdc++.h>
using namespace std;

const int inf = 0x3f3f3f3f;
const int N = 505;
const int M = 10005;
int p[N], w[N], dp[N][M];
int main()
{
	int tt;
	scanf("%d", &tt);
	while (tt--) {
		memset(dp, inf, sizeof(inf));
		int e, f, n, d;
		scanf("%d%d%d", &e, &f, &n);
		int d =  f - e;
		for (int i = 0; i < n; i++)
			scanf("%d %d", p + i, w + i);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < M; j++) {
				
			}
		}
	}
	return 0;
}