#include <iostream>
#include <cstdio>
using namespace std;
const int N = 1005;
const int M = 20005;
struct edge {
	int x, xx, h;
	bool operator < (const edge &a) const {
		return h < a.h;
	}
} e[N];
int dp[N][M];
int main()
{
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, x, y, mx, height = 0;
		scanf("%d %d %d %d", &n, &x, &y, &mx);
		for (int i = 1; i <= n; i++) {
			scanf("%d %d %d", &e[i].x, &e[i].xx, &e[i].h);
			height = max(height, e[i].h);
		}
		sort(e + 1, e + n + 1);
		for (int i = 1; i <= n; i++) {
			
			dp[i][j] += min(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	return 0;
}
