#include <iostream>
#include <cstdio>
#include <queue>
#include <map>
#include <string>
using namespace std;

const int N = 35;
map<string, int> mp;
int c[N];
int inq[N];
double dis[N][N];
int main()
{
	int n, k;
	int cas = 1;
	while (~scanf("%d", &n) && n) {
		for (int i = 0; i < n; i++) {
			string str;
			cin >> str;
			mp[str] = i;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dis[i][j] = 1.0 * 1e4;
			}
			dis[i][i] = 1.0;
		}
		scanf("%d", &k);
		for (int i = 0; i < k; i++) {
			string x, y;
			double m;
			cin >> x >> m >> y;
			dis[mp[x]][mp[y]] = m;
		}
		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (dis[i][j] < dis[i][k] * dis[k][j]) {
						dis[i][j] = dis[i][k] * dis[k][j];
					}
				}
			}
		}
		int ok = 0;
		for (int i = 0; i < n; i++) {
			if (dis[i][i] > 1.0) {
				ok = 1;
				break;
			}
		}
		if (ok) {
			printf("Case %d: Yes\n", cas++);
		} else {
			printf("Case %d: No\n", cas++);
		}
	}
	return 0;
}
