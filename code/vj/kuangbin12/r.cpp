#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int M = 1005;
struct node {
	int s, e, f;
	bool operator < (const node & op) const {
		return s < op.s || s == op.s && e < op.e;
	}
} e[M];
int dp[M];
int main()
{
	int n, m, r;
	scanf("%d %d %d", &n, &m, &r);
	for (int i = 1; i <= m; i++) {
		scanf("%d %d %d", &e[i].s, &e[i].e, &e[i].f);
	}
	sort(e + 1, e + m + 1);
	int ans = 0;
	for (int i = 1; i <= m; i++) {
		dp[i] = e[i].f;
		for (int j = 1; j < i; j++) {
			if (e[j].s - e[i].e >= r || e[i].s - e[j].e >= r) {
				if (dp[i] < dp[j] + e[i].f) {
					dp[i] = dp[j] + e[i].f;
				}
			}
		}
		ans = max(dp[i], ans);
	}
	printf("%d\n", ans);
	return 0;
}