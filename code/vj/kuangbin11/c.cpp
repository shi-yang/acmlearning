#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <map>
using namespace std;
const int N = 805;
const int inf = (int) 1e9;
int n, m, k;
int s, t;
map<string, int> ss;
int G[N][N];
int path[N];
bool bfs()
{
	queue<int> que;
	que.push(s);
	memset(path, -1, sizeof(path));
	path[s] = s;
	while (!que.empty()) {
		int now = que.front();
		que.pop();
		for (int i = 0; i < N; i++) {
			if (G[now][i] > 0 && path[i] == -1) {
				path[i] = now;
				if (i == t) {
					return true;
				}
				que.push(i);
			}
		}
	}
	return false;
}
int maxflow()
{
	int res = 0;
	while (bfs()) {
		int mi = inf;
		for (int i = t; i != s; i = path[i]) {
			mi = min(mi, G[path[i]][i]);
		}
		for (int i = t; i != s; i = path[i]) {
			G[path[i]][i] -= mi;
			G[i][path[i]] += mi;
		}
		res += mi;
	}
	return res;
}
int main()
{
	while (~scanf("%d", &n)) {
		ss.clear();
		memset(G, 0, sizeof(G));
		s = 0, t = N - 1;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			string str;
			cin >> str;
			ss[str] = ++cnt;
			G[cnt][t] = 1;
		}
		scanf("%d", &m);
		for (int i = 0; i < m; i++) {
			string x, y;
			cin >> x >> y;
			ss[x] = ++cnt;
			if (!ss[y]) {
				ss[y] = ++cnt;
			}
			G[ss[x]][ss[y]] = 1;
			G[s][ss[x]] = 1;
		}
		scanf("%d", &k);
		for (int i = 0; i < k; i++) {
			string x, y;
			cin >> x >> y;
			if (!ss[x]) {
				ss[x] = ++cnt;
			}
			if (!ss[y]) {
				ss[y] = ++cnt;
			}
			G[ss[x]][ss[y]] = inf;
		}
		printf("%d\n", m - maxflow());
	}
	return 0;
}