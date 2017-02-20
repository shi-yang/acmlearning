#include <bits/stdc++.h>
using namespace std;
int main()
{
	int tt;
	cin >> tt;
	while (tt--) {
		int a, b;
		cin >> a >> b;
		int n;
		cin >> n;
		double ans = 99999999;
		for (int i = 0; i < n; i++) {
			int x, y, v;
			cin >> x >> y >> v;
			double t = sqrt(1.0 * ((x - a) * (x - a) + (y - b) * (y - b)));
			t /= v;
			ans = min(ans, t);
		}
		printf("%.2lf\n", ans);
	}
	return 0;
}
