#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int n, q;
struct point {
	int x, y;
} p[N];
struct edge {
	int from, to, cost;
	bool operator < (const edge & a) const {
		return cost < a.cost;
	}
} e[N * N];
int f[N * N];
int root(int x)
{
	return x == f[x] ? x : f[x] = root(f[x]);
}
vector<int> vip[10];
int vipcost[10];
int main()
{
	int tt;
	scanf("%d", &tt);
	bool flag = false;
	while (tt--) {
		if (flag)
			putchar('\n');
		if (!flag)
			flag = true;
		scanf("%d %d", &n, &q);
		for (int i = 0; i < q; i++) {
			vip[i].clear();
			int a;
			scanf("%d %d", &a, &vipcost[i]);
			while (a--) {
				int x;
				scanf("%d", &x);
				vip[i].push_back(x);
			}
		}
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &p[i].x, &p[i].y);
		}
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				int cost = (p[i].x - p[j].x) * (p[i].x - p[j].x) + (p[i].y - p[j].y) * (p[i].y - p[j].y);
				e[cnt].from = i + 1;
				e[cnt].to = j + 1;
				e[cnt].cost = cost;
				cnt++;
			}
		}
		sort(e, e + cnt);
		int ans = (int) 1e9;
		for (int s = 0; s < 1 << q; s++) {
			int cost = 0;
			for (int i = 1; i <= cnt; i++) {
				f[i] = i;
			}
			for (int i = 0; i < q; i++) {
				if (s & 1 << i) {
					cost += vipcost[i];
					for (int k = 0; k < (int) vip[i].size() - 1; k++) {
						f[root(vip[i][k])] = root(vip[i][k + 1]);
					}
				}
			}
			for (int i = 0; i < cnt; i++) {
				if (root(e[i].from) == root(e[i].to))
					continue;
				f[root(e[i].from)] = root(e[i].to);
				cost += e[i].cost;
			}
			ans = min(ans, cost);
		}
		cout << ans << endl;
	}
	return 0;
}