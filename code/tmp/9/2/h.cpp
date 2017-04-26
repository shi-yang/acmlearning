#include <iostream>
#include <cstdio>

using namespace std;

const int N = 205;
struct project {
	int cc, c[5];
	project () {}
	project (int ccc, int * t) {
		cc = ccc;
		for (int i = 0; i < ccc; i++)
			c[i] = t[i];
	}
}p[N];
int cnt;
vector<int> G[N];
int main()
{
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, m;
		cnt = 0;
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++) {
			int c[5], cc;
			scanf("%d", &cc);
			for (int j = 0; j < cc; j++) {
				scanf("%d", c + j);
			}
			p[++cnt] = project(cc, c);
			G[0].push_back(cnt);
		}
		for (int i = 0; i < m; i++) {
			int dd, d[5];
			scanf("%d", &dd);
			for (int j = 0; j < dd; j++) {
				scanf("%d", d + j);
			}
			p[++cnt] = project(dd, d);
			G[cnt].push_back(N);
		}
		for (int i = 1; i <= n; i++) {
			
			for (int j = n + 1; j <= n + 1 + m; j++) {
			
			}
		}
	}
	return 0;
}
