#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int N = 205;
const int inf = 0x3f3f3f3f;
int a[N];
int d[N];
int cnt[N];
int inq[N];
int m, n;
vector<int> G[N];

int power(int n)
{
	return n * n * n;
}

int spfa()
{
	queue<int> que;
	que.push(1);
	memset(d, inf, sizeof(d));
	memset(cnt, 0, sizeof(cnt));
	memset(inq, 0, sizeof(inq));
	d[1] = 0;
	inq[1] = 1;
	while (!que.empty()) {
		int now = que.front();
		que.pop();
		inq[now] = 0;
		for (int i = 0; i < (int)G[now].size(); i++) {
			int u = G[now][i];
			int df = power(a[u] - a[now]);
			if (d[u] > d[now] + df) {
				d[u] = d[now] + df;
				if (inq[u])
					continue;
				if (cnt[u]++ > n) {
					return false;
				}
				inq[u]++;
				que.push(u);
			}
		}
	}
	return true;
}

int main()
{
	int t, kase = 1;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			G[i].clear();
			scanf("%d", &a[i]);
		}
		scanf("%d", &m);
		for (int i = 0; i < m; i++) {
			int u, v;
			scanf("%d %d", &u, &v);
			G[u].push_back(v);
		}
		int ok = spfa();
		int q;
		scanf("%d", &q);
		printf("Case %d:\n", kase++);
		while (q--) {
			int u;
			scanf("%d", &u);
			if (d[u] < 3 || d[u] == inf) {
				printf("?\n");
			} else {
				printf("%d\n", d[u]);
			}
		}
	}
	return 0;
}