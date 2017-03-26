#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int w[maxn], sum[maxn];
int main()
{
	int n, l, r, ql, qr;
	cin >> n >> l >> r >> ql >> qr;
	for (int i = 1; i <= n; i++) {
		cin >> w[i];
		sum[i] = sum[i - 1] + w[i];
	}
	int ans = INT_MAX;
	for (int i = 0; i <= n; i++) {
		int t = l * sum[i] + r * (sum[n] - sum[i]);
		if (i > n - i)
			t += (i * 2 - n - 1) * ql;
		if (i < n - i)
			t += (n - i * 2 - 1) * qr;
		ans = min(ans, t);
	}
	cout << ans << endl;
	return 0;
}
