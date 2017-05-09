#include <bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
	int t, n, m;
	scanf("%d", &t);
	while (t--) {
		memset(a, 0, sizeof(a));
		cin >> n >> m;
		while (n--) {
			int x, y;
			cin >> x;
			while (x--) {
				cin >> y;
				a[y] = 1;
			}
		}
		int ok = 1;
		while (m--) {
			if (!a[i])	ok = 0;
		}
		cout << ok ? "YES" : "NO" << endl;
	}
	return 0;
}
