#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
const int maxn = 105;
struct edge {
	int t;
	double r, c;
	edge(){}
	edge(int t, double r, double c) : t(t), r(r), c(c) {}
}e[maxn];
int inq[maxn];
double d[maxn];
int cnt[maxn];
vector<edge> G[maxn];
bool spfa(int s, double mo, int n)
{
	memset(inq, 0, sizeof(inq));
	memset(cnt, 0, sizeof(cnt));
	inq[s] = 1;
	d[s] = mo;
	queue<int> que;
	que.push(s);
	while (que.size()) {
		int now = que.front();
		que.pop();
		inq[now] = 0;
		for (int i = 0; i < G[now].size(); i++) {
			edge v = G[now][i];
			double tmp = (d[now] - v.c) * v.r;
			if (d[v.t] < tmp) {
				d[v.t] = tmp;
				if (inq[v.t])
					continue;
				inq[v.t] = 1;
				que.push(v.t);
				cnt[v.t]++;
				if (cnt[v.t] > n)
					return true;
			}
		}
	}
	if (d[s] > mo)
		return true;
	else
		return false;
}
int main()
{
	int n, m, s;
	double v;
	cin >> n >> m >> s >> v;
	for (int i = 1; i <= m; i++) {
		int a, b;
		double c, d, e, f;
		cin >> a >> b >> c >> d >> e >> f;
		G[a].push_back(edge(b, c, d));
		G[b].push_back(edge(a, e, f));
	}
	if (spfa(s, v, n)) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	return 0;
}
