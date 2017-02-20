#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int x[maxn], m[maxn];
int main()
{
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> x[i];
		}
		int q;
		cin >> q;
		sort(x, x + n);
		for (int i = 0; i < q; i++) {
			int a;
			cin >> a;
			int cnt = 0;
			for (int j = 0; j < n; j++) {
				if (x[j] > a) {
					break;
				} else {
					cnt++;
				}
			}
      //更好的写法，不用 for 循环，而是　cnt = upper_bound(x, x + n, m) - x;
			cout << cnt << endl;
		}
	}
	return 0;
}
