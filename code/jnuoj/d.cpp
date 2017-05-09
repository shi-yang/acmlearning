#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		int mx, mi, ans = 0;
		for (;;) {
			mx = max(a, b);
			mi = min(a, b);
			ans++;
			a++;
			b -= 2;
			if (a < 2 && b < 2)
				break;
		}
		ans--;
		cout << ans << endl;
	}
	return 0;
}
