#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int main()
{
	int n;
	cin >> n;
	int k = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		k = __gcd(a[i], k);
	}
	cout << "YES" << endl;
	if (k > 1) {
		cout << 0 << endl;
		return 0;
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] & 1) {
			if (a[i + 1] & 1) {
				ans += 2;
			} else {
				ans += 1;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
