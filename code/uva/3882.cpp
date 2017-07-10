#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, k, m;
	while (~scanf("%d %d %d", &n, &k, &m), n) {
		int f = 0;
		for (int i = 2; i <= n; i++) {
			f = (f + k) % i;
		}
		int ans = (m - k + 1 + f) % n;
		if (ans <= 0)
			ans += n;
		cout << ans << endl;
	}
	return 0;
}
