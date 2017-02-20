#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int x[maxn], y[maxn];
int main()
{
	int tt;
	cin >> tt;
	while (tt--) {
		memset(x, 0, sizeof(x));
		memset(y, 0, sizeof(y));
		long long n, m;
		cin >> n >> m;
		long long ans = n * n;
		int tx = 0, ty = 0;
		int a, b;
		for (int i = 0; i < m; i++) {
			cin >> a >> b;
			if (!x[a])
				ans -= (n - ty);
			if (!y[b])
				ans -= (n - tx);
			if (!x[a] && !y[b])
				ans++;
			if (!x[a])
				tx++;
			if (!y[b])
				ty++;
			x[a] = y[b] = 1;
			cout << ans << ' ';
		}
		cout << endl;
	}
	return 0;
}
Distributed under GPLv3. | Project Homepage | Developer: 51isoft crccw | 二次开发： Semprathlon | Current Style: Original.

Select Style:   Fluid Width?
 
