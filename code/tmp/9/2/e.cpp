#include <iostream>
#include <cstdio>
using namespace std;
const int N = 1e5 + 5;
struct edge {
	int x, y;
}e[N];
int main()
{
	int tt;
	cin >> tt;
	for (int ii = 1; ii <= tt; ii++) {
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &e[i].x, &e[i].y);
		}
		int mi = 1e9, mx = 0;
		for (int i = 0; i < m; i++) {
			int x;
			scanf("%d", &x);
			mi = min(mi, x);
			mx = max(mx, x);
		}
		int a = 0, b = 0;
		for (int i = 0; i < n; i++) {
			if (e[i].x <= mi && mx <= e[i].y) {
				a++;
			} else {
				b++;
			}
		}
		cout << a << ' ' << b << endl;
		if (a == 0) {
			printf("Case #%d: IMPOSSIBLE!\n", ii);
		} else if (b >= a) {
			printf("Case #%d: %d\n", ii, b + 1);
		} else {
			printf("Case #%d: %d\n", ii, a);
		}
	}
	return 0;
}
