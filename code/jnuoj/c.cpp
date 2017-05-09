#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t, n, m;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		long long ans = 0;
		while (n--) {
			ans -= n / 5;
			ans += (n + m) / 5;
		}
		cout << ans << endl;
	}
	return 0;
}
