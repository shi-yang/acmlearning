#include <bits/stdc++.h>

using namespace std;

const int N = 10005;

int dfn[N], low[N], dfs_clock, scc_cnt, sccno[N];
int n, m;
int cnt;
struct edge {
	int to, next;
} e[N * 10];
int head[N];
void add_edge(int u, int v)
{
	e[++cnt].to = v, e[cnt].next = head[u], head[u] = cnt;
}
stack<int> s;
void dfs(int u)
{
	dfn[u] = low[u] = ++dfs_clock;
	s.push(u);
	for (int i = head[u]; i; i = e[i].next) {
		if (!dfn[e[i].to]) {
			dfs(e[i].to);
			low[u] = min(low[u], low[e[i].to]);
		} else {
			low[u] = min(low[u], dfn[e[i].to]);
		}
	}
	if (dfn[u] == low[u]) {
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
	while (~scanf("%d %d", &n, &m) && (m + n)) {
		cnt = 0;
		memset(head, 0, sizeof(head));
		for (int i = 0; i < m; i++) {
			int u, v;
			scanf("%d %d", &u, &v);
			add_edge(u, v);
		}
		scc_cnt = dfs_clock = 0;
		memset(dfn, 0, sizeof(dfn));
		memset(sccno, 0, sizeof(sccno));
		for (int i = 1; i <= n; i++) {
			if (!dfn[i])
				dfs(i);
		}
		if (scc_cnt == 1) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}
	return 0;
}