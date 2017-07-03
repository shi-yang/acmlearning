#include <bits/stdc++.h>
using namespace std;
const int N = 20;
struct edge {
	char name[105];
	int d, c;
} e[N];
int dp[N][1 << N];
int main()
{
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%s %d %d", e[i].name, &e[i].d, &e[i].c);
		}
		for (int i = 0; i < n; i++) {
			dp[i][1] = 
		}
	}
	return 0;
}
