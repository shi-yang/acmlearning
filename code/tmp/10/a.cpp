#include <bits/stdc++.h>
using namespace std;
long long lowbit(long long x)
{
	return x & (-x);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n, q, p;
	cin >> n >> q;
	p = (n + 1) >> 1;
	while (q--) {
		long long u;
		string s;
		cin >> u >> s;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'U') {
				if (u == p)
					continue;
				long long pp = u + lowbit(u);
				pp -= lowbit(pp) >> 1;
				if (pp == u) {
					u += lowbit(u);
				} else {
					u -= lowbit(u);
				}
			} else if (s[i] == 'L') {
				u -= lowbit(u) >> 1;
			} else {
				u += lowbit(u) >> 1;
			}
		}
		cout << u << endl;
	}
	return 0;
}
