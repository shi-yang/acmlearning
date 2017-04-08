#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005;
long long a[maxn];
map <int, int> isp;
void getpr()
{
	for (int i = 1; i < maxn; i++) {
		a[i] = i * (i + 1) / 2;
		isp[a[i]] = 1;
	}
}
int main()
{
	getpr();
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		bool t = false;
		for (int i = 1; i < maxn; i++) {
			if (n > a[i] && isp[n - a[i]]) {
				t = true;
				break;
			}
		}
		if (t) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
}
