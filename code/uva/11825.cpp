#include <bits/stdc++.h>
using namespace std;

const int N = 20;
int p[N];
int dp[N][1 << N];
int main()
{
	int n, cas = 1;
	while (~scanf("%d", &n), n) {
		for (int i = 0; i < n; i++) {
			int m, x;
			scanf("%d", &m);
			p[i] = 1 << i;
			while (m--) {
				scanf("%d", &x);
				p[i] |= 1 << x;
			}
		}
		
	}
	return 0;
}
