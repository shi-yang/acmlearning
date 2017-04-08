#include <bits/stdc++.h>
using namespace std;
int main()
{
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		int ans = 1;
		int t = 1;
		while (1) {
			t *= 2;
			if (t > n)
				break;
			else
				ans = t;
		}
		cout << ans << endl;
	}
	return 0;
}
