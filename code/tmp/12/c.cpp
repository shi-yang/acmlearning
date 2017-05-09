#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mdx = 5837501;
const int mdy = 9860381;
const int maxn = 1e6 + 5;
const int inf = 1e9;
int n, m;
ll x[maxn], y[maxn], z[maxn];
int dis[1005][1005];
int d[1005];
int inq[1005];
void spfa()
{
	queue<int> que;
	que.push(0);
	inq[0] = 1;
	for (int i = 1; i < n; i++) {
		d[i] = inf;
	}
	d[0] = 0;
	while (que.size()) {
		int now = que.front();
		que.pop();
		for (int i = 0; i < n; i++) {
			if (d[i] > d[now] + dis[now][i]) {
				d[i] = d[now] + dis[now][i];
				if (inq[i])
					continue;
				inq[i] = 1;
				que.push(i);
			}
		}
		inq[now] = 0;
	}
}
int main()
{
	while (~scanf("%d %d %lld %lld %lld %lld", &n, &m, &x[0], &x[1], &y[0], &y[1])) {
		for (int k = 0; k < n * n; k++) {
			if (k >= 2) {
				x[k] = (12345 + x[k - 1] * 23456 + x[k - 2] * 34567 + x[k - 1] * x[k - 2] * 45678) % mdx;
				y[k] = (56789 + y[k - 1] * 67890 + y[k - 2] * 78901 + y[k - 1] * y[k - 2] * 89012) % mdy;
			}
			z[k] = (x[k] * 90123 + y[k]) % 8475871 + 1;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i != j) dis[i][j] = (int)z[i * n + j];
				else dis[i][j] = 0;
			}
		}
		spfa();
		int mi = 1e9;
		for (int i = 1; i < n; i++) {
			mi = min(mi, d[i] % m);
		}
		cout << mi << endl;
	}
	return 0;
}
