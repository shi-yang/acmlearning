#include <bits/stdc++.h>
using namespace std;
const int maxn = 16;
const int inf = 1e9;
struct edge {
	string name;
	int s, d;
} e[maxn];
struct kdp {
	int t, s, p, now;
} dp[1 << maxn];
int main()
{
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			cin >> e[i].name >> e[i].s >> e[i].d;
		}
		for (int i = 0; i < 1 << n; i++) {
			dp[i].s = inf;
			for (int j = 0; j <= n - 1; j++) {
				if (i & 1 << j) {
					int p = i - (1 << j);
					int s = dp[p].t + e[i].s - e[i].d;
					if (s < 0)
						s = 0;
					if (s + dp[p].s < dp[s].s) {
						dp[s].s = s + dp[p].s;
						dp[s].now = i;
						dp[s].p = p;
						dp[s].t = dp[p].t + e[i].s;
					}
				}
			}
		}
		stack<int> s;
		int tmp = (1 << n) - 1;
		cout << dp[tmp].s << endl;
		while (tmp) {
			s.push(dp[tmp].now);
			tmp = dp[tmp].p;
		}
		while (!s.empty()) {
			cout << e[s.top()].name << endl;
			s.pop();
		}
	}
	return 0;
}
