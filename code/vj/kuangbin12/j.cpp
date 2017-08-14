#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
struct node {
	int s, v, id;
	bool operator < (const node &op) const {
		return v > op.v;
	}
} e[N];
int rec[N], dp[N];
int main()
{
	int m = 1;
	while (~scanf("%d %d", &e[m].s, &e[m].v)) {
		e[m].id = m;
		m++;
	}
	m--;
	sort(e + 1, e + m + 1);
	int mx = 0, pos = 0;
	for (int i = 1; i <= m; i++) {
		dp[i] = 1;
		for (int j = 1; j < i; j++) {
			if (e[i].s > e[j].s && e[i].v < e[j].v && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
				rec[i] = j;
			}
		}
		if (dp[i] > mx) {
			mx = dp[i];
			pos = i;
		}
	}
	stack<int> ans;
	while (pos) {
		ans.push(pos);
		pos = rec[pos];
	}
	printf("%d\n", ans.size());
	while (!ans.empty()) {
		printf("%d\n", e[ans.top()].id);
		ans.pop();
	}
	return 0;
}