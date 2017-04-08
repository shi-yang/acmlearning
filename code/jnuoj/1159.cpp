#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
const int maxn = 2005;
int f[maxn], n, m;
struct edge
{
    int u, v, w;
}e[maxn];
bool cmp(edge x,edge y)
{
    return x.w < y.w;
}
int root(int x)
{
    while (x != f[x])
        x = f[x];
    return x;
}
bool connected(int x, int y)
{
		return root(x) == root(y);
}
int Kruskal()
{
		int ans = 0;
		sort(e, e + m, cmp);
		int amax = -1;
		for (int i = 0; i < m; i++) {
				if (connected(e[i].u, e[i].v))
						continue;
				f[root(e[i].u)] = root(e[i].v);
				ans += e[i].w;
				amax = max(e[i].w, amax);
		}
		return ans - amax;
}
int main()
{
    int t;
		scanf("%d", &t);
    while(t--) {
				scanf("%d%d", &n, &m);
        for(int i = 0; i < m; i++)
            scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
        for(int i = 0;i <= n; i++)
            f[i] = i;
        printf("%d\n", Kruskal());
    }
    return 0;
}
