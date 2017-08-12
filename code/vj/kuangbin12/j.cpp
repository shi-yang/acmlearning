#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 1005;
struct node {
	int s, v, id;
	bool operator < (const node &op) const {
		return v > op.v;
	}
} e[N];
int G[N], ans[N];
int main()
{
	int m = 1;
	while (~scanf("%d %d", &e[m].s, &e[m].v)) {
		e[m].id = m;
		m++;
	}
	cout << m << endl;
	sort(e + 1, e + m);
	memset(G, INF, sizeof(G));
	memset(ans, INF, sizeof(ans));
	G[0] = 0;
	int mx = 0;
	for (int i = 1; i < m; i++) {
		int k = lower_bound(G + 1, G + 1 + m, e[i].s) - G;
		G[k] = e[i].s;
		cout << "k:" << k << ' ' << "G[" << k << "]:" << G[k] << endl;
		mx = max(mx, k);
	}
	for (int i = 1; i <= mx; i++) {
		printf("%d\n", G[i]);
	}
	return 0;
}