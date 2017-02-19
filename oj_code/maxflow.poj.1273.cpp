#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int maxn = 205;
struct edge {
	int to, cap, rev;
};
vector<edge> g[maxn];
bool vis[maxn];
void add_edge(int from, int to, int cap)
{
	g[from].push_back((edge){to, cap, g[to].size()});
	g[to].push_back((edge) {from, 0, g[from].size() - 1});
}
int dfs(int v, int t, int f)
{
	if (v == t)
		return f;
	vis[v] = 1;
	for (int i = 0; i < g[v].size(); i++) {
		edge &e = g[v][i];
		if (!vis[e.to] && e.cap > 0) {
			int d = dfs(e.to, t, min(f, e.cap));
			if (d > 0) {
				e.cap -= d;
				g[e.to][e.rev].cap += d;
				return d;
			}
		}
	}
	return 0;
}
int main()
{
	int n, m;
	while (scanf("%d%d", &n, &m) != EOF) {
		int a, b, c;
		for (int i = 0; i < n; i++) {
			cin >> a >> b >> c;
			add_edge(a, b, c);
		}
		int flow = 0;
		for (;;) {
			memset(vis, 0, sizeof(vis));
			int f = dfs(1, m, 999999);
			if (f == 0) {
				break;
			}
			flow += f;
		}
		cout << flow << endl;
	}
	return 0;
}
