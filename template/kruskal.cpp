#include <bits/stdc++.h>
using namespace std;
const int maxn = 100;
struct edge {
	int u, v, w;
} e[maxn];
int f[maxn], n, m;
bool cmp(edge a, edge b)
{
	return a.w < b.w;
}
int root(int x)
{
	return x == f[x] ? x : f[x] = root(f[x]);
}
int kruskal()
{
	int ans = 0;
	sort(e, e + n, cmp);
	for (int i = 0; i <= n; i++) {
		f[i] = i;
	}
	for (int i = 0; i < m; i++) {
		if (root(e[i].u) == root(e[i].v))
			continue;
		f[root(e[i].u)] = root(e[i].v);
		ans += e[i].w;
	}
	return ans;
}

int main()
{
	return 0;
}
