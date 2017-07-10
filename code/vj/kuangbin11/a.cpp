#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int inf = (int) 1e4;
const int N = 105;
const int P = 15;
int n, p;
int d[N][P];
int G[N][N];
int back[N][N];
int f[N];
int path[N];
int s, t;
int line[N][3];
void add_edge(int from, int to, int cost)
{
	G[from][to] = cost;
}
void build_map()
{
	for (int i = 0; i < n; i++)
		add_edge(i, i + n, f[i]);
	for (int i = 0; i < n; i++) {
		int ok = 1;
		for (int j = 0; j < p; j++) {
			if (d[i][j] == 1) {
				ok = 0;
				break;
			}
		}
		if (ok) {
			add_edge(s, i, inf);
		}
		ok = 1;
		for (int j = 0; j < p; j++) {
			if (d[i + n][j] != 1) {
				ok = 0;
				break;
			}
		}
		if (ok) {
			add_edge(i + n, t, inf);
		}
		for (int j = 0; j < n; j++) {
			if (i == j)
				continue;
			ok = 1;
			for (int k = 0; k < p; k++) {
				if (d[j][k] != 2 && d[j][k] != d[i + n][k]) {
					ok = 0;
					break;
				}
			}
			if (ok) {
				add_edge(n + i, j, inf);
			}
		}
	}
}

bool bfs(int from, int to)
{
	queue<int> que;
	que.push(from);
	memset(path, -1, sizeof(path));
	path[from] = from;
	while (!que.empty()) {
		int now = que.front();
		que.pop();
		for (int i = 0; i < N; i++) {
			if (G[now][i] > 0 && path[i] == -1) {
				path[i] = now;
				if (i == to) {
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
	while (bfs(s, t)) {
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
	scanf("%d %d", &p, &n);
	s = n + n + 1, t = n + n + 2;
	for (int i = 0; i < n; i++) {
		scanf("%d", &f[i]);
		for (int j = 0; j < p; j++) {
			scanf("%d", &d[i][j]);
		}
		for (int j = 0; j < p; j++) {
			scanf("%d", &d[i + n][j]);
		}
	}
	build_map();
	memcpy(back, G, sizeof(G));
	int ans = maxflow();
	int cnt = 0;
	for (int i = n; i < n + n; i++) {
		for (int j = 0; j < n; j++) {
			if (G[i][j] < back[i][j] ) {
				line[cnt][0] = i - n + 1;
				line[cnt][1] = j + 1;
				line[cnt][2] = back[i][j] - G[i][j];
				cnt++;
			}
		}
	}
	printf("%d %d\n", ans, cnt);
	for (int i = 0; i < cnt; i++) {
		printf("%d %d %d\n", line[i][0], line[i][1], line[i][2]);
	}
	return 0;
}