#include <bits/stdc++.h>

using namespace std;
const double eps = 1e-10;
const int N = 10005;
vector<int> G[N];
double A[N], B[N], C[N];
struct edge {
	double k, e;
} d[N];
bool dfs(int u, int pre)
{
	if (G[u].size() == 1 && pre != -1) {
		A[u] = d[u].k;
		B[u] = 1 - d[u].k - d[u].e;
		C[u] = 1 - d[u].k - d[u].e;
		return true;
	}
	A[u] = d[u].k;
	B[u] = (1 - d[u].k - d[u].e) / G[u].size();
	C[u] = 1 - d[u].k - d[u].e;
	double tmp = 0;
	for (int i = 0; i < (int) G[u].size(); i++) {
		if (G[u][i] == pre)
			continue;
		if (!dfs(G[u][i], u))
			return false;
		A[u] += A[G[u][i]] * B[u];
		C[u] += C[G[u][i]] * B[u];
		tmp += B[G[u][i]] * B[u];
	}
	if (fabs(tmp - 1) < eps)
		return false;
	A[u] /= (1 - tmp);
	B[u] /= (1 - tmp);
	C[u] /= (1 - tmp);
	return true;
}
int main()
{
	int t;
	scanf("%d", &t);
	for (int cas = 1; cas <= t; cas++) {
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			G[i].clear();
		for (int i = 1; i < n; i++) {
			int u, v;
			scanf("%d %d", &u, &v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		for (int i = 1; i <= n; i++) {
			int k, e;
			scanf("%d %d", &k, &e);
			d[i].k = k / 100.0;
			d[i].e = e / 100.0;
		}
		printf("Case %d: ", cas);
		if (dfs(1, -1) && fabs(1 - A[1]) > eps) {
			printf("%.6lf\n", C[1] / (1 - A[1]));
		} else {
			printf("impossible\n");
		}
	}
	return 0;
}