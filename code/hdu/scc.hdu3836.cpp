#include <bits/stdc++.h>
using namespace std;
const int N =20005;
int n, m;
struct edge {
	int to, next;
} e[50005];
int cnt, head[N];
void add_edge(int u, int v)
{
	e[++cnt].to = v, e[cnt].next = head[u], head[u] = cnt;
}
int sccno[N], scc_cnt, dfs_clock, dfn[N], low[N];
stack<int> s;
int in[N], out[N];
void dfs(int u)
{
	low[u] = dfn[u] = ++dfs_clock;
	s.push(u);
	for (int i = head[u]; i; i = e[i].next) {
		if (!dfn[e[i].to]) {
			dfs(e[i].to);
			low[u] = min(low[u], low[e[i].to]);
		} else if (!sccno[e[i].to]) {
			low[u] = min(low[u], dfn[e[i].to]);
		}
	}
	if (low[u] == dfn[u]) {
		scc_cnt++;
		for (;;) {
			int x = s.top();
			s.pop();
			sccno[x] = scc_cnt;
			if (x == u)
				break;
		}
	}
}
int main()
{
	while (~scanf("%d %d", &n, &m)) {
		cnt = 0;
		memset(head, 0, sizeof(head));
		for (int i = 0; i < m; i++) {
			int u, v;
			scanf("%d %d", &u, &v);
			add_edge(u, v);
		}
		dfs_clock = scc_cnt = 0;
		memset(sccno, 0, sizeof(sccno));
		memset(dfn, 0, sizeof(dfn));
		for (int i = 1; i <= n; i++) {
			if (!dfn[i])
				dfs(i);
		}
		memset(in, 0, sizeof(in));
		memset(out, 0, sizeof(out));
		for (int u = 1; u <= n; u++) {
			for (int i = head[u]; i; i = e[i].next) {
				int v = e[i].to;
				if (sccno[v] != sccno[u]) {
					in[sccno[v]]++;
					out[sccno[u]]++;
				}
			}
		}
		int a = 0, b = 0;
		for (int i = 1; i <= scc_cnt; i++) {
			if (!in[i])
				a++;
			if (!out[i])
				b++;
		}
		printf("%d\n", scc_cnt == 1 ? 0 : max(a, b));
	}
	return 0;
}