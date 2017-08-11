#include <bits/stdc++.h>
using namespace std;
const int N = 105;
struct edge {
	int t, c, id;
	bool operator < (const edge &a) const {
		return t < a.t || t == a.t && c > a.c;
	}
} e[N];
int main()
{
	int n;
	while (~scanf("%d", &n)) {
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &e[i].t, &e[i].c);
			e[i].id = i;
		}
		sort(e, e + n);

	}
	return 0;
}