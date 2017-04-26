#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 1e5 + 5;
int w[N];
int d[N];
int main()
{
	int t;
	scanf("%d", &t);
	int cas = 1;
	while (t--) {
		int l, n, m;
		scanf("%d %d %d", &l, &n, &m);
		for (int i = 0; i < n; i++) {
			scanf("%d", w + i);
		}
		for (int i = 0; i < m; i++) {
			scanf("%d", d + i);
		}
		sort(w, w + n);
		sort(d, d + m);
		printf("Case #%d: %d", cas++, ans);
	}
	return 0;
}
