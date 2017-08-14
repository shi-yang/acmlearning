#include <bits/stdc++.h>
using namespace std;
const int maxn = 16;
const int inf = 1e9;
struct edge {
	string name;
	int day, spent;
} e[maxn];
struct kdp {
	int time, pre, now, score;
} dp[1 << maxn];
int main()
{
	int t;
	scanf("%d", &t);
	while (t--) {
		memset(dp, 0, sizeof(dp));
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			cin >> e[i].name >> e[i].day >> e[i].spent;
		}
		for (int i = 1; i < 1 << n; i++) {
			dp[i].score = inf;
			for (int j = n - 1; j >= 0; j--) {
				if (i & 1 << j) {
					int past = i - (1 << j);
					int score = dp[past].time + e[j].spent - e[j].day;
					if (score < 0)
						score = 0;
					if (score + dp[past].score < dp[i].score) {
						dp[i].score = score + dp[past].score;
						dp[i].now = j;
						dp[i].pre = past;
						dp[i].time = dp[past].time + e[j].spent;
					}
				}
			}
		}
		stack<int> s;
		int tmp = (1 << n) - 1;
		cout << dp[tmp].score << endl;
		while (tmp) {
			s.push(dp[tmp].now);
			tmp = dp[tmp].pre;
		}
		while (!s.empty()) {
			cout << e[s.top()].name << endl;
			s.pop();
		}
	}
	return 0;
}
