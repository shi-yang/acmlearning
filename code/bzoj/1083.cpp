#include <bits/stdc++.h>
using namespace std;
const int N = 400;
const int M = 10005;
struct edge {
	int u, v, c;
	bool operator < (const edge & a) const {
		return c < a.c;
	}
} e[M];
int f[N];
int root(int x)
{
	return x == f[x] ? x : f[x] = root(f[x]);
}
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].c);
	}
	for (int i = 1; i <= n; i++)
		f[i] = i;
	sort(e, e + m);
	int ans;
	for (int i = 0; i < m; i++) {
		if (root(e[i].u) != root(e[i].v)) {
			f[root(e[i].u)] = root(e[i].v);
			ans = e[i].c;
		}
	}
	printf("%d %d\n", n - 1, ans);
	return 0;
}